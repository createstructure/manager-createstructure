# manager-createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/CastellaniDavide/manager-createstructure-manager-createstructure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v1.0-blue?style=flat) ![Language ...](https://img.shields.io/badge/language-...-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-...-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/createstructure/manager-createstructure)

## Description
Repo where there is everything you need for server management

## Table of contents
- [manager-createstructure](#manager-createstructure)
  - [Description](#description)
  - [Table of contents](#table-of-contents)
  - [Directories structure](#directories-structure)
  - [Installation](#installation)
    - [Requirements](#requirements)
    - [Install](#install)
    - [Run](#run)
  - [Repo dependencies](#repo-dependencies)


## Directories structure
```
├── bin
│   ├── libraries
│   │   ├── createstructure_changes.hpp
│   │   ├── createstructure_chooseTemplate.hpp
│   │   ├── createstructure_cryptation.hpp
│   │   ├── createstructure_download.hpp
│   │   ├── createstructure_elaborate.hpp
│   │   ├── createstructure_emoji.hpp
│   │   ├── createstructure.hpp
│   │   ├── createstructure_inputCheck.hpp
│   │   ├── createstructure_memory.hpp
│   │   ├── createstructure_positive.hpp
│   │   ├── createstructure_replace.hpp
│   │   ├── createstructure_rest.hpp
│   │   ├── createstructure_split.hpp
│   │   ├── createstructure_upload.hpp
│   │   ├── createstructure_work.hpp
│   │   └── json.hpp
│   └── manager.cpp
├── debian
│   ├── changelog
│   ├── compat
│   ├── control
│   ├── copyright
│   ├── createstructure.dirs
│   ├── files
│   ├── postinst
│   ├── postrm
│   ├── preinst
│   ├── rules
│   └── source
│       └── format
├── docs
│   ├── LICENSE
│   └── README.md
├── .git
│   └── ...
├── .github
│   └── workflows
│       └── publish.yml
├── Makefile
├── manager.1
└── requirements.in

```

## Installation
### Requirements
 - apt
 
### Install
 - `sudo add-apt-repository ppa:castellanidavide/createstructure; sudo apt update; sudo apt install manager`

### Run
 - `manager`

## Repo dependencies
 - [nlohmann/json](https://github.com/nlohmann/json)


---
Made by Castellani Davide 
If you have any problem please contact me:
- help@castellanidavide.it
- [Issue](https://github.com/createstructure/manager-createstructure/issues)
