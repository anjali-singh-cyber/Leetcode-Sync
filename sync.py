import os
import time
import requests
from dotenv import load_dotenv

load_dotenv()

SESSION = os.getenv("LEETCODE_SESSION")

HEADERS = {
    "Cookie": f"LEETCODE_SESSION={SESSION}",
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0"
}

BASE_URL = "https://leetcode.com/graphql"
TARGET_REPO = "C:/Users/hp/OneDrive/DSA_Journey"
SYNC_FILE = "last_sync.txt"


# -------------------------
# GraphQL helper
# -------------------------
from requests.exceptions import RequestException
def graphql(query, variables=None):
    for attempt in range(5):
        try:
            response = requests.post(
                BASE_URL,
                json={
                    "query": query,
                    "variables": variables or {}
                },
                headers=HEADERS,
                timeout=30
            )

            response.raise_for_status()
            return response.json()

        except RequestException as e:
            print(f"Request failed ({attempt + 1}/5): {e}")

            if attempt < 4:
                print("Retrying in 5 seconds...")
                time.sleep(5)
            else:
                raise
# -------------------------
# Sync state helpers
# -------------------------
def get_last_sync():
    if not os.path.exists(SYNC_FILE):
        return 0

    with open(SYNC_FILE, "r") as f:
        return int(f.read().strip())


def save_last_sync(timestamp):
    with open(SYNC_FILE, "w") as f:
        f.write(str(timestamp))

def initialize_last_sync():
    query = """
    query Submissions($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          statusDisplay
          timestamp
        }
      }
    }
    """

    data = graphql(query, {
        "offset": 0,
        "limit": 20
    })

    subs = data["data"]["submissionList"]["submissions"]

    for s in subs:
        if s["statusDisplay"] == "Accepted":
            save_last_sync(int(s["timestamp"]))
            print("Initialized last_sync.txt")
            return

# -------------------------
# Fetch all submissions
# -------------------------
def fetch_all_submissions():
    offset = 0
    limit = 20
    all_subs = []

    while True:
        query = """
        query Submissions($offset: Int!, $limit: Int!) {
          submissionList(offset: $offset, limit: $limit) {
            submissions {
              id
              title
              titleSlug
              statusDisplay
              lang
              timestamp
            }
          }
        }
        """

        data = graphql(query, {"offset": offset, "limit": limit})
        subs = data["data"]["submissionList"]["submissions"]

        if not subs:
            break

        all_subs.extend(subs)
        offset += limit

    return all_subs

def fetch_recent_submissions():
    query = """
    query Submissions($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          id
          title
          titleSlug
          statusDisplay
          lang
          timestamp
        }
      }
    }
    """

    data = graphql(query, {
        "offset": 0,
        "limit": 20
    })

    return data["data"]["submissionList"]["submissions"]
# -------------------------
# Get problem metadata
# -------------------------
def get_problem_info(slug):
    query = """
    query question($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
      questionFrontendId
        title
        difficulty
        topicTags {
          name
        }
      }
    }
    """

    return graphql(query, {"titleSlug": slug})["data"]["question"]


# -------------------------
# Get full code
# -------------------------
def get_code(submission_id):
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
      }
    }
    """

    return graphql(query, {"submissionId": submission_id})["data"]["submissionDetails"]["code"]


# -------------------------
# Filename builder
# -------------------------
def build_filename(info):
    qid = info["questionFrontendId"]
    title = info["title"]
    tags = [t["name"] for t in info["topicTags"]]


    tag_str = ", ".join(tags)

    filename = f"{qid} - {title} [{tag_str}].cpp"
    for ch in '<>:"/\\|?*':
        filename = filename.replace(ch, "-")

    return filename





# -------------------------
# Write solution
# -------------------------
import re

def write_solution(path, code, lang):
    os.makedirs(os.path.dirname(path), exist_ok=True)

    # Read existing content
    if os.path.exists(path):
        with open(path, "r", encoding="utf-8") as f:
            content = f.read()
    else:
        content = ""

    # Skip duplicate solutions
    if code.strip() in content:
        return

    lang_marker = f"Language: {lang}"

    # Determine method number for this language
    if lang_marker not in content:
        method_no = 1

        with open(path, "a", encoding="utf-8") as f:
            f.write(
                f"\n// =========================\n"
                f"// Language: {lang}\n"
                f"// =========================\n"
            )
    else:
        pattern = (
            rf"Language: {re.escape(lang)}"
            r"(.*?)(?=Language:|\Z)"
        )

        match = re.search(pattern, content, re.S)

        if match:
            section = match.group(1)
            method_no = section.count("Method") + 1
        else:
            method_no = 1

    with open(path, "a", encoding="utf-8") as f:
        f.write(
            f"\n// -------- Method {method_no} --------\n\n"
        )
        f.write(code)
        f.write("\n\n")
     


import subprocess

def push_to_github():
    subprocess.run(
        ["git", "add", "."],
        cwd=TARGET_REPO,
        check=True
    )

    status = subprocess.run(
        ["git", "status", "--porcelain"],
        cwd=TARGET_REPO,
        capture_output=True,
        text=True
    )

    if not status.stdout.strip():
        print("No changes to push.")
        return

    subprocess.run(
        ["git", "commit", "-m", "Sync LeetCode progress"],
        cwd=TARGET_REPO,
        check=True
    )

    subprocess.run(
        ["git", "push"],
        cwd=TARGET_REPO,
        check=True
    )

    print("GitHub updated successfully.")
def has_changes():
     result = subprocess.run(
        ["git", "status", "--porcelain"],
        cwd=TARGET_REPO,
        capture_output=True,
        text=True
    )

     return bool(result.stdout.strip())

# -------------------------
# Main pipeline
# -------------------------

import os
import time
import requests
from dotenv import load_dotenv

load_dotenv()

SESSION = os.getenv("LEETCODE_SESSION")

HEADERS = {
    "Cookie": f"LEETCODE_SESSION={SESSION}",
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0"
}

BASE_URL = "https://leetcode.com/graphql"
TARGET_REPO = "C:/Users/hp/OneDrive/DSA_Journey"
SYNC_FILE = "last_sync.txt"


# -------------------------
# GraphQL helper
# -------------------------
from requests.exceptions import RequestException
def graphql(query, variables=None):
    for attempt in range(5):
        try:
            response = requests.post(
                BASE_URL,
                json={
                    "query": query,
                    "variables": variables or {}
                },
                headers=HEADERS,
                timeout=30
            )

            response.raise_for_status()
            return response.json()

        except RequestException as e:
            print(f"Request failed ({attempt + 1}/5): {e}")

            if attempt < 4:
                print("Retrying in 5 seconds...")
                time.sleep(5)
            else:
                raise
# -------------------------
# Sync state helpers
# -------------------------
def get_last_sync():
    if not os.path.exists(SYNC_FILE):
        return 0

    with open(SYNC_FILE, "r") as f:
        return int(f.read().strip())


def save_last_sync(timestamp):
    with open(SYNC_FILE, "w") as f:
        f.write(str(timestamp))

def initialize_last_sync():
    query = """
    query Submissions($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          statusDisplay
          timestamp
        }
      }
    }
    """

    data = graphql(query, {
        "offset": 0,
        "limit": 20
    })

    subs = data["data"]["submissionList"]["submissions"]

    for s in subs:
        if s["statusDisplay"] == "Accepted":
            save_last_sync(int(s["timestamp"]))
            print("Initialized last_sync.txt")
            return

# -------------------------
# Fetch all submissions
# -------------------------
def fetch_all_submissions():
    offset = 0
    limit = 20
    all_subs = []

    while True:
        query = """
        query Submissions($offset: Int!, $limit: Int!) {
          submissionList(offset: $offset, limit: $limit) {
            submissions {
              id
              title
              titleSlug
              statusDisplay
              lang
              timestamp
            }
          }
        }
        """

        data = graphql(query, {"offset": offset, "limit": limit})
        subs = data["data"]["submissionList"]["submissions"]

        if not subs:
            break

        all_subs.extend(subs)
        offset += limit

    return all_subs

def fetch_recent_submissions():
    query = """
    query Submissions($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          id
          title
          titleSlug
          statusDisplay
          lang
          timestamp
        }
      }
    }
    """

    data = graphql(query, {
        "offset": 0,
        "limit": 20
    })

    return data["data"]["submissionList"]["submissions"]
# -------------------------
# Get problem metadata
# -------------------------
def get_problem_info(slug):
    query = """
    query question($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
      questionFrontendId
        title
        difficulty
        topicTags {
          name
        }
      }
    }
    """

    return graphql(query, {"titleSlug": slug})["data"]["question"]


# -------------------------
# Get full code
# -------------------------
def get_code(submission_id):
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
      }
    }
    """

    return graphql(query, {"submissionId": submission_id})["data"]["submissionDetails"]["code"]


# -------------------------
# Filename builder
# -------------------------
def build_filename(info):
    qid = info["questionFrontendId"]
    title = info["title"]
    tags = [t["name"] for t in info["topicTags"]]


    tag_str = ", ".join(tags)

    filename = f"{qid} - {title} [{tag_str}].cpp"
    for ch in '<>:"/\\|?*':
        filename = filename.replace(ch, "-")

    return filename





# -------------------------
# Write solution
# -------------------------
import re

def write_solution(path, code, lang):
    os.makedirs(os.path.dirname(path), exist_ok=True)

    # Read existing content
    if os.path.exists(path):
        with open(path, "r", encoding="utf-8") as f:
            content = f.read()
    else:
        content = ""

    # Skip duplicate solutions
    if code.strip() in content:
        return

    lang_marker = f"Language: {lang}"

    # Determine method number for this language
    if lang_marker not in content:
        method_no = 1

        with open(path, "a", encoding="utf-8") as f:
            f.write(
                f"\n// =========================\n"
                f"// Language: {lang}\n"
                f"// =========================\n"
            )
    else:
        pattern = (
            rf"Language: {re.escape(lang)}"
            r"(.*?)(?=Language:|\Z)"
        )

        match = re.search(pattern, content, re.S)

        if match:
            section = match.group(1)
            method_no = section.count("Method") + 1
        else:
            method_no = 1

    with open(path, "a", encoding="utf-8") as f:
        f.write(
            f"\n// -------- Method {method_no} --------\n\n"
        )
        f.write(code)
        f.write("\n\n")
     


import subprocess

def push_to_github():
    subprocess.run(
        ["git", "add", "."],
        cwd=TARGET_REPO,
        check=True
    )

    status = subprocess.run(
        ["git", "status", "--porcelain"],
        cwd=TARGET_REPO,
        capture_output=True,
        text=True
    )

    if not status.stdout.strip():
        print("No changes to push.")
        return

    subprocess.run(
        ["git", "commit", "-m", "Sync LeetCode progress"],
        cwd=TARGET_REPO,
        check=True
    )

    subprocess.run(
        ["git", "push"],
        cwd=TARGET_REPO,
        check=True
    )

    print("GitHub updated successfully.")
def has_changes():
     result = subprocess.run(
        ["git", "status", "--porcelain"],
        cwd=TARGET_REPO,
        capture_output=True,
        text=True
    )

     return bool(result.stdout.strip())

def update_readme():
    print("Updating README...")
    easy_path = os.path.join(TARGET_REPO, "Easy")
    medium_path = os.path.join(TARGET_REPO, "Medium")
    hard_path = os.path.join(TARGET_REPO, "Hard")

    easy = len(os.listdir(easy_path)) if os.path.exists(easy_path) else 0
    medium = len(os.listdir(medium_path)) if os.path.exists(medium_path) else 0
    hard = len(os.listdir(hard_path)) if os.path.exists(hard_path) else 0

    total = easy + medium + hard

    readme = f"""# 🚀 DSA Journey

## 📊 Progress

- Total Problems Solved: {total}
- 🟢 Easy: {easy}
- 🟡 Medium: {medium}
- 🔴 Hard: {hard}

---

Last Updated: {time.strftime("%d %B %Y")}
"""

    readme_path = os.path.join(TARGET_REPO, "README.md")

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(readme)

# -------------------------
# Main pipeline
# -------------------------
def main():
    print("Fetching submissions...")

    # First-time initialization
    if not os.path.exists(SYNC_FILE):
        initialize_last_sync()
        return

    subs = fetch_recent_submissions()
    last_sync = get_last_sync()

    # Keep only newly accepted submissions
    accepted = [
        s for s in subs
        if s["statusDisplay"] == "Accepted"
        and int(s["timestamp"]) > last_sync
    ]

    # Group by problem
    grouped = {}

    for s in accepted:
        grouped.setdefault(
            s["titleSlug"],
            []
        ).append(s)

    print(f"Problems found: {len(grouped)}")

    for slug, submissions in grouped.items():

        problem_info = get_problem_info(slug)
        difficulty = problem_info["difficulty"]

        folder = difficulty
        filename = build_filename(problem_info)

        path = os.path.join(
            TARGET_REPO,
            folder,
            filename
        )

        for sub in sorted(
            submissions,
            key=lambda x: int(x["timestamp"])
        ):
            code = get_code(int(sub["id"]))
            lang = sub["lang"]

            write_solution(
                path,
                code,
                lang
            )

            time.sleep(1)

        print("Saved:", path)

    update_readme()
    print("Sync complete.")

    if has_changes():
        push_to_github()

    if accepted:
        newest = max(
            int(s["timestamp"])
            for s in accepted
        )
        save_last_sync(newest)

if __name__ == "__main__":
    main()