#!/bin/zsh

# Check if a project name was provided
if [ -z "$1" ]; then
    echo "Usage: makecpp <project_name>"
    exit 1
fi

# Inside your script, before creating directories:
PROJECT_NAME=$(echo "$1" | tr '[:upper:]' '[:lower:]' | tr ' ' '-')
DOCS_SOURCE="/home/maime/workspace/dev/vladimirazarov"

# Stop if directory already exists to prevent overwriting
if [ -d "$PROJECT_NAME" ]; then
    echo "Error: Directory '$PROJECT_NAME' already exists."
    exit 1
fi

echo "Creating project: $PROJECT_NAME..."

# 1. Create directory structure
mkdir -p "$PROJECT_NAME"/{src,include/"$PROJECT_NAME",tests,third_party,build,learn}

# 2. Copy reference files (Check if source exists first)
[ -f "$DOCS_SOURCE/cppstyle.md" ] && cp "$DOCS_SOURCE/cppstyle.md" "$PROJECT_NAME/learn/"
[ -f "$DOCS_SOURCE/cppnotes.md" ] && cp "$DOCS_SOURCE/cppnotes.md" "$PROJECT_NAME/learn/"

# 3. Create EMPTY CMakeLists.txt
touch "$PROJECT_NAME"/CMakeLists.txt

# 4. Create starter main.cc
cat <<EOF > "$PROJECT_NAME"/src/main.cc
#include <iostream>

int main() {
    std::cout << "Hello from $PROJECT_NAME!" << std::endl;
    return 0;
}
EOF

# 5. Create .gitignore
cat <<EOF > "$PROJECT_NAME"/.gitignore
build/
cmake-build-*/
bin/
lib/
third_party/
.vscode/
.idea/
*.swp
*.o
*.out
$PROJECT_NAME
EOF

# 6. Create README
echo "# $PROJECT_NAME" > "$PROJECT_NAME"/README.md

echo "Project '$PROJECT_NAME' created."
