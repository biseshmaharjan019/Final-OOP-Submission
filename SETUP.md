# Initial Setup Guide - SSH Configuration & Git Setup

Complete this guide to set up your local environment for submitting lab work to the bei-oop repository.

## 📋 Table of Contents

1. [System Requirements](#system-requirements)
2. [Install Git](#install-git)
3. [Configure Git](#configure-git)
4. [SSH Key Setup](#ssh-key-setup)
5. [Clone Repository](#clone-repository)
6. [Troubleshooting](#troubleshooting)

---

## ✅ System Requirements

- **Windows**: Windows 7 or later, macOS, or Linux
- **RAM**: 2GB minimum
- **Disk Space**: 1GB free space
- **Internet Connection**: Required for cloning and pushing

---

## 📦 Install Git

### Windows

1. Download Git from [https://git-scm.com/download/win](https://git-scm.com/download/win)
2. Run the installer
3. Select default options during installation
4. Open Command Prompt or Git Bash to verify:
   ```bash
   git --version
   ```

### macOS

Using Homebrew (recommended):
```bash
brew install git
```

Or download from [https://git-scm.com/download/mac](https://git-scm.com/download/mac)

Verify installation:
```bash
git --version
```

### Linux (Ubuntu/Debian)

```bash
sudo apt-get update
sudo apt-get install git
git --version
```

### Linux (Fedora/RHEL)

```bash
sudo yum install git
git --version
```

---

## 🔧 Configure Git

After installing Git, configure your identity:

### Step 1: Set Your Name

```bash
git config --global user.name "Your Full Name"
```

Example:
```bash
git config --global user.name "John Doe"
```

### Step 2: Set Your Email

```bash
git config --global user.email "your.email@example.com"
```

Example:
```bash
git config --global user.email "john.doe@university.edu"
```

### Step 3: Verify Configuration

```bash
git config --global --list
```

You should see:
```
user.name=John Doe
user.email=john.doe@university.edu
```

---

## 🔐 SSH Key Setup

SSH (Secure Shell) allows secure communication between your computer and GitHub.

### Step 1: Check for Existing SSH Keys

```bash
ls -la ~/.ssh
```

- If you see `id_rsa` and `id_rsa.pub`, you already have SSH keys. Skip to [Step 3](#step-3-add-ssh-key-to-github).
- If the `.ssh` folder doesn't exist or is empty, continue to [Step 2](#step-2-generate-new-ssh-keys).

### Step 2: Generate New SSH Keys

```bash
ssh-keygen -t rsa -b 4096 -C "your.email@example.com"
```

Replace `your.email@example.com` with your actual email.

You'll see:
```
Generating public/private rsa key pair.
Enter file in which to save the key (/home/username/.ssh/id_rsa):
```

Press **Enter** to accept the default location.

Next prompt:
```
Enter passphrase (empty for no passphrase):
```

**Option A**: Press **Enter** twice for no passphrase (easier, less secure)
**Option B**: Enter a strong passphrase and confirm it (more secure, requires password each time)

**Recommendation**: Use Option A for development machines, Option B for production/shared machines.

You'll see:
```
Your identification has been saved in /home/username/.ssh/id_rsa
Your public key has been saved in /home/username/.ssh/id_rsa.pub
```

### Step 3: Add SSH Key to GitHub

#### Step 3a: Copy Your Public Key

**Windows (Git Bash or PowerShell):**
```bash
cat ~/.ssh/id_rsa.pub | clip
```

**macOS:**
```bash
cat ~/.ssh/id_rsa.pub | pbcopy
```

**Linux:**
```bash
cat ~/.ssh/id_rsa.pub | xclip -selection clipboard
```

Or manually open and copy the contents:
```bash
cat ~/.ssh/id_rsa.pub
```

Select all text and copy it to clipboard.

#### Step 3b: Add Key to GitHub

1. Go to [https://github.com/settings/keys](https://github.com/settings/keys)
2. Click **New SSH key** (top right)
3. In the **Title** field, enter: `My Computer - OOP Lab`
4. Paste your public key into the **Key** field
5. Click **Add SSH key**
6. If prompted, enter your GitHub password to confirm

### Step 4: Test SSH Connection

```bash
ssh -T git@github.com
```

You'll see a prompt:
```
The authenticity of host 'github.com' can't be established.
ECDSA key fingerprint is SHA256:...
Are you sure you want to continue connecting (yes/no)?
```

Type **yes** and press Enter.

Success message:
```
Hi username! You've successfully authenticated, but GitHub does not provide shell access.
```

---

## 🔗 Clone Repository

Now you're ready to clone the repository!

### Step 1: Navigate to Your Working Directory

**Windows (Command Prompt):**
```bash
cd Desktop
```

**macOS/Linux:**
```bash
cd ~/Desktop
```

### Step 2: Clone the Repository

```bash
git clone git@github.com:su-ndey/bei-oop.git
```

You'll see:
```
Cloning into 'bei-oop'...
remote: Enumerating objects...
```

### Step 3: Enter the Repository Directory

```bash
cd bei-oop
```

### Step 4: Verify (Optional)

```bash
git status
```

You should see:
```
On branch main
nothing to commit, working tree clean
```

---

## 🐛 Troubleshooting

### Problem: "Permission denied (publickey)"

**Cause**: SSH key not properly configured or not added to GitHub.

**Solution**:
1. Verify SSH key exists:
   ```bash
   ls ~/.ssh/id_rsa
   ```
2. Check if key is added to GitHub: [https://github.com/settings/keys](https://github.com/settings/keys)
3. Test connection again:
   ```bash
   ssh -T git@github.com
   ```

### Problem: "git: command not found"

**Cause**: Git is not installed or not in your PATH.

**Solution**:
1. Reinstall Git from [https://git-scm.com](https://git-scm.com)
2. Restart your terminal/command prompt
3. Verify: `git --version`

### Problem: "Could not resolve hostname github.com"

**Cause**: Internet connection issue.

**Solution**:
1. Check your internet connection
2. Try pinging GitHub:
   ```bash
   ping github.com
   ```
3. Try HTTPS clone instead:
   ```bash
   git clone https://github.com/su-ndey/bei-oop.git
   ```

### Problem: "Host key verification failed"

**Cause**: SSH connection not properly established.

**Solution**:
1. Test SSH connection:
   ```bash
   ssh -T git@github.com
   ```
2. Accept the host key when prompted
3. Try cloning again

### Problem: Repository Already Cloned Error

**Cause**: Folder `bei-oop` already exists.

**Solution**:
```bash
# Option 1: Remove the existing folder
rm -rf bei-oop

# Option 2: Clone to a different name
git clone git@github.com:su-ndey/bei-oop.git bei-oop-new
```

---

## 📝 Next Steps

After completing this setup:

1. Read the main [README.md](./README.md) for submission guidelines
2. Create your folder with your name
3. Start adding your lab work
4. Follow the commit and push instructions in README.md

---

## 🎓 Quick Reference Commands

```bash
# Show Git version
git --version

# Show Git configuration
git config --global --list

# Test SSH connection
ssh -T git@github.com

# Clone repository
git clone git@github.com:su-ndey/bei-oop.git

# Navigate to repository
cd bei-oop

# Check repository status
git status

# Stage changes
git add .

# Commit changes
git commit -m "Your message here"

# Push to GitHub
git push origin main

# View commit history
git log
```

---

## ✅ Setup Complete!

You're all set! Proceed to the [README.md](./README.md) file to start submitting your lab work.

For any issues, refer to the troubleshooting section above or contact your instructor.

**Happy coding! 🚀**
