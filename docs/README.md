# manager-createstructure	##  Description 	##  Class UML 	##  Directory structure 	manager (10.01.09~distribution) distribution; urgency=medium	##  Rebuild the manager-createstructure locally 	---
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](//blob//docs/LICENSE)	Repo for managing the creation of the repos	![Class UML](https://raw.githubusercontent.com/createstructure/manager-createstructure/beta/docs/manager-createstructure-Class-UML.svg)			Install the manager-create locally permits you to do some debug and try new configurations.	Made w/ :heart: by Castellani Davide
![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat)	![createstructure/manager-createstructure](https://opengraph.githubassets.com/a3a4d15708489c549f21651878ad646c0fbcb3d26e994358d5b77dcf3304b062/createstructure/manager-createstructure)		```	  * [Split .hpp files into modules (.hpp and .cpp)](https://github.com/createstructure/manager-createstructure/issues/16)		
![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-all-blue?style=flat) 			../repo		### Steps:	If you want to contribute you can start with:
			├── Class-UML.md	 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 22:00:00 +1000	- [ Rebuild the manager-createstructure locally ](#octocat-rebuild-the-manager-createstructure-locally-octocat)	- [Discussion](//discussions)
			├── Makefile		  - [Steps:](#steps)	- [Issue](//issues/new)
			├── bin # source code	manager (10.01.07~distribution) distribution; urgency=medium	  - [1. Install VirtualBox on the PC](#1-install-virtualbox-on-the-pc)	
			│   ├── global-libraries		  - [2. Install Ubuntu](#2-install-ubuntu)	
			│   │   ├── bin # source code	  * [Ubuntu 22.04](https://github.com/createstructure/manager-createstructure/issues/15)	  - [3. Install dependencies](#3-install-dependencies)	
			│   │   │   ├── cryptation.cpp		  - [4. Compile](#4-compile)	
			│   │   │   ├── cryptation.hpp	 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 17:00:00 +1000		
			│   │   │   ├── emoji.cpp		### 1. Install VirtualBox on the PC	
			│   │   │   ├── emoji.hpp	manager (10.01.06) distribution; urgency=medium	For installation we suggest VirtualBox, a tool that allows you to create one or more virtual machines :computer:.	
			│   │   │   ├── inputs.cpp		If any of these crashes, in any case, your PC will not lose data, at most you will have to restart it :smile:.	
			│   │   │   ├── inputs.hpp	  * [Upgrade docs automation](https://github.com/createstructure/manager-createstructure/issues/14)		
			│   │   │   ├── json.hpp	  * [Ubuntu 22.04](https://github.com/createstructure/manager-createstructure/issues/15)	To install VirtualBox on your PC you need to:	
			│   │   │   ├── positive.cpp		- Get in into the UEFI	
			│   │   │   ├── positive.hpp	 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 15:30:00 +1000	- Enable the function which name is like \	
			│   │   │   ├── rest.cpp	 	Virtualization\ (for each UEFI this step is different but similar)	
			│   │   │   ├── rest.hpp	manager (10.01.05) focal; urgency=medium	- Save the configuration and restart the PC	
			│   │   │   ├── sleep.cpp		- Go to the [VirtualBox website](https://www.virtualbox.org/)	
			│   │   │   └── sleep.hpp	  * [Added charts automation](https://github.com/createstructure/manager-createstructure/issues/12)	- Press \	
			│   │   └── docs # documentation		Download\	
			│   │       ├── CHANGELOG.md	 -- Castellani Davide <help@castellanidavide.it>  Sat, 12 Mar 2022 19:00:00 +1000	- Run the downloaded file	
			│   │       ├── LICENSE		- Follow the installation steps	
			│   │       ├── README.md	manager (10.01.04) focal; urgency=medium		
			│   │       ├── libraries-createstructure-Class-UML.svg		### 2. Install Ubuntu	
			│   │       └── libraries-createstructure.drawio	  * [Add sponsorship button](https://github.com/createstructure/createstructure.github.io/issues/36)	As the OS we suggest to use Ubuntu, because it is lightweight (for RAM and CPU) and it's free.	
			│   ├── local-libraries			
			│   │   ├── help.cpp	 -- Castellani Davide <help@castellanidavide.it>  Wed, 5 Jan 2022 14:00:00 +1000	To install Ubuntu on VirtualBox you need to:	
			│   │   ├── help.hpp		- Download the last LTS version of Ubuntu by the following link: [https://ubuntu.com/download/desktop](https://ubuntu.com/download/desktop)	
			│   │   ├── login.cpp	manager (10.01.03) focal; urgency=medium	> Now you can continue with the other steps during the download	
			│   │   ├── login.hpp		- Open VirtualBox	
			│   │   ├── memory.cpp	  * [Fix installation on ARM archittecture](https://github.com/createstructure/manager-createstructure/issues/10)	- Press \	
			│   │   ├── memory.hpp	  * [Fix minikube startup](https://github.com/createstructure/manager-createstructure/issues/11)	New\	
			│   │   ├── version.cpp		- Compile the form	
			│   │   └── version.hpp	 -- Castellani Davide <help@castellanidavide.it>  Sat, 16 Dec 2021 12:10:00 +1000	    - As name put \	
			│   ├── manager.cpp		rest-createstructure\	
			│   └── manager.yml	manager (10.01.02) focal; urgency=medium	    - As Type: \	
			├── debian # debian control code		Linux\	
			│   ├── changelog	  * [beta => latest](https://github.com/createstructure/manager-createstructure/issues/9)	- Leave \	
			│   ├── compat		Create	
			│   ├── control	 -- Castellani Davide <help@castellanidavide.it>  Sat, 11 Dec 2021 23:15:00 +1000	a	
			│   ├── copyright		virtual	
			│   ├── manager.dirs	manager (10.01.01) focal; urgency=medium	hard	
			│   ├── postinst		disk	
			│   ├── postrm	  * [Create a Docker management system](https://github.com/createstructure/manager-createstructure/issues/3)	now\ and press \Create\	
			│   ├── preinst	  * [Create service for the new REST API](https://github.com/createstructure/manager-createstructure/issues/4)	- Change the hard disk memory, we suggest 16GB and press \	
			│   ├── rules	  * [Create a routine to automate the Docker container management](https://github.com/createstructure/manager-createstructure/issues/5)	Create\	
			│   └── source	  * [Include install.sh in the manager-createstructure debian package](https://github.com/createstructure/manager-createstructure/issues/1)	> Make sure that Ubuntu download is finished before to continue	
			│       └── format	  * [Convert functions into classes in all libraries](https://github.com/createstructure/manager-createstructure/issues/6)	- On the VirtualBox console, selecting the created VM, press \	
			├── docs # documentation	  * [Improve documentation](https://github.com/createstructure/manager-createstructure/issues/7)	Start\	
			│   ├── LICENSE		- Select as start-up disk Ubuntu, already downloaded	
			│   ├── README.md	 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Dec 2021 22:00:00 +1000	    - Press the folder icon	
			│   ├── manager-createstructure-Class-UML.svg		    - Press \	
			│   └── manager-createstructure.drawio	manager (09.01.20) focal; urgency=medium	Add\, in the top menu	
			├── manager.1		    - Select the Ubuntu iso, the file will have a structure like \	
			└── requirements.in	  * Try to change reboot waiting-time (3h => 6h)	ubuntu-version-other_info.iso\	
					    - Press \	
			8 directories, 46 files	 -- Castellani Davide <help@castellanidavide.it>  Tue, 07 Sep 2021 08:05:00 +1000	Choose\ and \Start\	
			```		- Follow the install steps (the installation needs some minutes)	
				manager (09.01.19) focal; urgency=medium		
					### 3. Install dependencies	
				  * Change reboot waiting-time (12h => 3h)	Now you have to install building dependencies.	
						
				 -- Castellani Davide <help@castellanidavide.it>  Mon, 13 Aug 2021 16:00:00 +1000	To install Dependes on the Virtual Machine you need to:	
					- On the VM (Virtual Machine) open the terminal (\Ctrl + Alt + T\)	
				manager (09.01.18) focal; urgency=medium		
					### 4. Compile	
				  * Added help management	To compile type: \`dpkg-buildpackage -us -uc\`	
						
				 -- Castellani Davide <help@castellanidavide.it>  Mon, 19 Jul 2021 10:45:00 +1000	Now the .deb file is in the ../ folder, you can install it with apt.	
						
				manager (09.01.17) focal; urgency=medium		
						
				  * Updated librerias		
				  * Optimized importations		
				  * Formatted source		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sun, 18 Jul 2021 14:30:00 +1000		
						
				manager (09.01.16) focal; urgency=medium		
						
				  * auto-reboot now "stable"		
				  * removed file "files"		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 14:15:00 +1000		
						
				manager (09.01.15) focal; urgency=medium		
						
				  * Test auto-reboot #2		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 13:15:00 +1000		
						
				manager (09.01.14) focal; urgency=medium		
						
				  * Test auto-reboot		
						
				 -- Castellani Davide <help@castellanidavide.it>  Thu, 15 Jul 2021 15:15:00 +1000		
						
				manager (09.01.13) focal; urgency=medium		
						
				  * Fixed a bug		
						
				 -- Castellani Davide <help@castellanidavide.it>  Tue, 13 Jul 2021 21:15:00 +1000		
						
				manager (09.01.12) focal; urgency=medium		
						
				  * Fixed a bug		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sun, 11 Jul 2021 10:15:00 +1000		
						
				manager (09.01.11) focal; urgency=medium		
						
				  * Added auto-reboot every 12h		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 10 Jul 2021 20:30:00 +1000		
						
				manager (09.01.10) focal; urgency=medium		
						
				  * Fixed a bug		
						
				 -- Castellani Davide <help@castellanidavide.it>  Fri, 07 Jul 2021 15:00:00 +1000		
						
				manager (09.01.09) focal; urgency=medium		
						
				  * Optimized some librerias		
						
				 -- Castellani Davide <help@castellanidavide.it>  Fri, 07 Jul 2021 14:45:00 +1000		
						
				manager (09.01.08) focal; urgency=medium		
						
				  * Changed librerias management		
						
				 -- Castellani Davide <help@castellanidavide.it>  Fri, 25 Jun 2021 9:15:00 +1000		
						
				manager (09.01.07) focal; urgency=medium		
						
				  * Changed docker		
						
				 -- Castellani Davide <help@castellanidavide.it>  Tue, 22 Jun 2021 21:10:00 +1000		
						
				manager (09.01.06) focal; urgency=medium		
						
				  * Added ARM availability		
						
				 -- Castellani Davide <help@castellanidavide.it>  Mon, 21 Jun 2021 17:55:00 +1000		
						
				manager (09.01.05) focal; urgency=medium		
						
				  * fixed a bug		
				  * Added install.sh in the repo		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sun, 20 Jun 2021 10:00:00 +1000		
						
				manager (09.01.04) focal; urgency=medium		
						
				  * Enabled debug to find the error		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sun, 20 Jun 2021 8:30:00 +1000		
						
				manager (09.01.03) focal; urgency=medium		
						
				  * Fixed a bug		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 22:00:00 +1000		
						
				manager (09.01.02) focal; urgency=medium		
						
				  * Fixed a bug w/ Docker container		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 21:00:00 +1000		
						
				manager (09.01.01) focal; urgency=medium		
						
				  * Initial version		
						
				 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 16:00:00 +1000		
