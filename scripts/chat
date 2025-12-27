#!/usr/bin/env python3
import sys
import os
import json
import urllib.request
import urllib.error
from rich.console import Console
from rich.markdown import Markdown

# --- CONFIGURATION ---
# 1. Get Key from Environment (set in ~/.zshrc)
API_KEY = os.environ.get("GEMINI_API_KEY")
if not API_KEY:
    console = Console()
    console.print("[bold red]Error:[/bold red] GEMINI_API_KEY not found in environment.")
    console.print("Make sure you added [bold]export GEMINI_API_KEY='...'[/bold] to your ~/.zshrc")
    sys.exit(1)

# 2. Settings
HISTORY_FILE = "/tmp/gemini_chat_history.json"
MODEL = "gemini-2.5-flash" # Use "gemini-2.0-flash" if this fails

# Initialize Rich Console
console = Console()

def load_history():
    if os.path.exists(HISTORY_FILE):
        with open(HISTORY_FILE, "r") as f:
            try:
                return json.load(f)
            except:
                return []
    return []

def save_history(history):
    with open(HISTORY_FILE, "w") as f:
        json.dump(history, f)

def ask_gemini(user_input, history):
    # Prepare payload
    contents = []
    for msg in history:
        role = "user" if msg["role"] == "user" else "model"
        contents.append({"role": role, "parts": [{"text": msg["text"]}]})
    
    contents.append({"role": "user", "parts": [{"text": user_input}]})
    
    data = {
        "contents": contents,
        "generationConfig": {"temperature": 0.7}
    }

    url = f"https://generativelanguage.googleapis.com/v1beta/models/{MODEL}:generateContent?key={API_KEY}"
    headers = {'Content-Type': 'application/json'}
    
    try:
        req = urllib.request.Request(url, data=json.dumps(data).encode('utf-8'), headers=headers)
        
        # Show loading spinner
        with console.status("[bold green]Thinking...", spinner="dots"):
            with urllib.request.urlopen(req) as response:
                result = json.loads(response.read().decode('utf-8'))
                answer = result.get('candidates', [{}])[0].get('content', {}).get('parts', [{}])[0].get('text', '')

        if answer:
            console.print("\n[bold blue]Gemini:[/bold blue]")
            # Render Markdown (colors code, fixes headings)
            console.print(Markdown(answer))
            console.print("") 
            
            history.append({"role": "user", "text": user_input})
            history.append({"role": "model", "text": answer})
            save_history(history)
        else:
            console.print("[red]Error: Empty response.[/red]")

    except urllib.error.HTTPError as e:
        console.print(f"[bold red]API Error {e.code}:[/bold red] {e.read().decode('utf-8')}")
    except Exception as e:
        console.print(f"[bold red]System Error:[/bold red] {e}")

def main():
    history = load_history()

    # MODE 1: Single Command (chat "how are you")
    if len(sys.argv) > 1:
        user_input = " ".join(sys.argv[1:])
        ask_gemini(user_input, history)
        sys.exit(0)

    # MODE 2: Interactive Loop (Super+C)
    console.clear()
    console.print(f"[bold green]>>> Gemini Anti-ADHD Mode[/bold green] (Model: {MODEL})")
    console.print("[dim]Type 'clear' to reset memory. Press Ctrl+D to exit.[/dim]")
    
    while True:
        try:
            # Standard input prompt
            user_input = input("\n\033[1;36mYou:\033[0m ")
            
            if user_input.lower() in ['exit', 'quit']: break
            if not user_input.strip(): continue

            # --- CLEAR LOGIC MOVED HERE (Before sending to AI) ---
            if user_input.lower() == 'clear':
                if os.path.exists(HISTORY_FILE):
                    os.remove(HISTORY_FILE)
                    # We must also clear the local variable 'history'
                    history.clear() 
                    console.print("[yellow]Memory cleared![/yellow]")
                else:
                    console.print("[dim]Memory already empty.[/dim]")
                continue
            # -----------------------------------------------------
            
            ask_gemini(user_input, history)
            
        except (KeyboardInterrupt, EOFError):
            console.print("\n[dim]Bye.[/dim]")
            break

if __name__ == "__main__":
    main()
