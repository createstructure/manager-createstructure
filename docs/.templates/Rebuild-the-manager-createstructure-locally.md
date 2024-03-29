## :octocat: Rebuild the manager-createstructure locally :octocat:
Install the manager-create locally permits you to do some debug and try new configurations.

### Steps:
- [:octocat: Rebuild the manager-createstructure locally :octocat:](#octocat-rebuild-the-manager-createstructure-locally-octocat)
  - [Steps:](#steps)
  - [1. Install VirtualBox on the PC](#1-install-virtualbox-on-the-pc)
  - [2. Install Ubuntu](#2-install-ubuntu)
  - [3. Install dependencies](#3-install-dependencies)
  - [4. Compile](#4-compile)

### 1. Install VirtualBox on the PC
For installation we suggest VirtualBox, a tool that allows you to create one or more virtual machines :computer:.
If any of these crashes, in any case, your PC will not lose data, at most you will have to restart it :smile:.

To install VirtualBox on your PC you need to:
- Get in into the UEFI
- Enable the function which name is like \
Virtualization\ (for each UEFI this step is different but similar)
- Save the configuration and restart the PC
- Go to the [VirtualBox website](https://www.virtualbox.org/)
- Press \
Download\
- Run the downloaded file
- Follow the installation steps

### 2. Install Ubuntu
As the OS we suggest to use Ubuntu, because it is lightweight (for RAM and CPU) and it's free.

To install Ubuntu on VirtualBox you need to:
- Download the last LTS version of Ubuntu by the following link: [https://ubuntu.com/download/desktop](https://ubuntu.com/download/desktop)
> Now you can continue with the other steps during the download
- Open VirtualBox
- Press \
New\
- Compile the form
    - As name put \
rest-createstructure\
    - As Type: \
Linux\
- Leave \
Create
a
virtual
hard
disk
now\ and press \Create\
- Change the hard disk memory, we suggest 16GB and press \
Create\
> Make sure that Ubuntu download is finished before to continue
- On the VirtualBox console, selecting the created VM, press \
Start\
- Select as start-up disk Ubuntu, already downloaded
    - Press the folder icon
    - Press \
Add\, in the top menu
    - Select the Ubuntu iso, the file will have a structure like \
ubuntu-version-other_info.iso\
    - Press \
Choose\ and \Start\
- Follow the install steps (the installation needs some minutes)

### 3. Install dependencies
Now you have to install building dependencies.

To install Dependes on the Virtual Machine you need to:
- On the VM (Virtual Machine) open the terminal (\Ctrl + Alt + T\)

### 4. Compile
To compile type: \`dpkg-buildpackage -us -uc\`

Now the .deb file is in the ../ folder, you can install it with apt.

