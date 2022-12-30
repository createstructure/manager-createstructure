##  Description 
Repo for managing the creation of the repos
![createstructure/manager-createstructure](https://opengraph.githubassets.com/16cd278fc8b98db91de36ae56485fb8b5011db0208b85a9be918e64a7489fe6d/createstructure/manager-createstructure)
##  Class UML 
![Class UML](https://raw.githubusercontent.com/createstructure/manager-createstructure/beta/docs/manager-createstructure-Class-UML.svg)
##  Directory structure 

```
../repo
├── Makefile
├── bin # source code
│   ├── global-libraries
│   │   ├── bin # source code
│   │   │   ├── cryptation.cpp
│   │   │   ├── cryptation.hpp
│   │   │   ├── emoji.cpp
│   │   │   ├── emoji.hpp
│   │   │   ├── inputs.cpp
│   │   │   ├── inputs.hpp
│   │   │   ├── json.hpp
│   │   │   ├── positive.cpp
│   │   │   ├── positive.hpp
│   │   │   ├── rest.cpp
│   │   │   ├── rest.hpp
│   │   │   ├── sleep.cpp
│   │   │   └── sleep.hpp
│   │   └── docs # documentation
│   │       ├── CHANGELOG.md
│   │       ├── LICENSE
│   │       ├── README.md
│   │       ├── libraries-createstructure-Class-UML.svg
│   │       └── libraries-createstructure.drawio
│   ├── local-libraries
│   │   ├── help.cpp
│   │   ├── help.hpp
│   │   ├── login.cpp
│   │   ├── login.hpp
│   │   ├── memory.cpp
│   │   ├── memory.hpp
│   │   ├── version.cpp
│   │   └── version.hpp
│   ├── manager.cpp
│   └── manager.yml
├── debian # debian control code
│   ├── changelog
│   ├── compat
│   ├── control
│   ├── copyright
│   ├── manager.dirs
│   ├── postinst
│   ├── postrm
│   ├── preinst
│   ├── rules
│   └── source
│       └── format
├── docs # documentation
│   ├── LICENSE
│   ├── README.md
│   ├── manager-createstructure-Class-UML.svg
│   └── manager-createstructure.drawio
├── manager.1
└── requirements.in

8 directories, 45 files
```
manager (10.01.09~distribution) distribution; urgency=medium

  * [Split .hpp files into modules (.hpp and .cpp)](https://github.com/createstructure/manager-createstructure/issues/16)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 22:00:00 +1000

manager (10.01.07~distribution) distribution; urgency=medium

  * [Ubuntu 22.04](https://github.com/createstructure/manager-createstructure/issues/15)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 17:00:00 +1000

manager (10.01.06) distribution; urgency=medium

  * [Upgrade docs automation](https://github.com/createstructure/manager-createstructure/issues/14)
  * [Ubuntu 22.04](https://github.com/createstructure/manager-createstructure/issues/15)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 27 Dec 2022 15:30:00 +1000
 
manager (10.01.05) focal; urgency=medium

  * [Added charts automation](https://github.com/createstructure/manager-createstructure/issues/12)

 -- Castellani Davide <help@castellanidavide.it>  Sat, 12 Mar 2022 19:00:00 +1000

manager (10.01.04) focal; urgency=medium

  * [Add sponsorship button](https://github.com/createstructure/createstructure.github.io/issues/36)

 -- Castellani Davide <help@castellanidavide.it>  Wed, 5 Jan 2022 14:00:00 +1000

manager (10.01.03) focal; urgency=medium

  * [Fix installation on ARM archittecture](https://github.com/createstructure/manager-createstructure/issues/10)
  * [Fix minikube startup](https://github.com/createstructure/manager-createstructure/issues/11)

 -- Castellani Davide <help@castellanidavide.it>  Sat, 16 Dec 2021 12:10:00 +1000

manager (10.01.02) focal; urgency=medium

  * [beta => latest](https://github.com/createstructure/manager-createstructure/issues/9)

 -- Castellani Davide <help@castellanidavide.it>  Sat, 11 Dec 2021 23:15:00 +1000

manager (10.01.01) focal; urgency=medium

  * [Create a Docker management system](https://github.com/createstructure/manager-createstructure/issues/3)
  * [Create service for the new REST API](https://github.com/createstructure/manager-createstructure/issues/4)
  * [Create a routine to automate the Docker container management](https://github.com/createstructure/manager-createstructure/issues/5)
  * [Include install.sh in the manager-createstructure debian package](https://github.com/createstructure/manager-createstructure/issues/1)
  * [Convert functions into classes in all libraries](https://github.com/createstructure/manager-createstructure/issues/6)
  * [Improve documentation](https://github.com/createstructure/manager-createstructure/issues/7)

 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Dec 2021 22:00:00 +1000

manager (09.01.20) focal; urgency=medium

  * Try to change reboot waiting-time (3h => 6h)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 07 Sep 2021 08:05:00 +1000

manager (09.01.19) focal; urgency=medium

  * Change reboot waiting-time (12h => 3h)

 -- Castellani Davide <help@castellanidavide.it>  Mon, 13 Aug 2021 16:00:00 +1000

manager (09.01.18) focal; urgency=medium

  * Added help management

 -- Castellani Davide <help@castellanidavide.it>  Mon, 19 Jul 2021 10:45:00 +1000

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
��# #   : o c t o c a t :   R e b u i l d   t h e   m a n a g e r - c r e a t e s t r u c t u r e   l o c a l l y   : o c t o c a t :  
 I n s t a l l   t h e   m a n a g e r - c r e a t e   l o c a l l y   p e r m i t s   y o u   t o   d o   s o m e   d e b u g   a n d   t r y   n e w   c o n f i g u r a t i o n s .  
  
 # # #   S t e p s :  
 -   [ : o c t o c a t :   R e b u i l d   t h e   m a n a g e r - c r e a t e s t r u c t u r e   l o c a l l y   : o c t o c a t : ] ( # o c t o c a t - r e b u i l d - t h e - m a n a g e r - c r e a t e s t r u c t u r e - l o c a l l y - o c t o c a t )  
     -   [ S t e p s : ] ( # s t e p s )  
     -   [ 1 .   I n s t a l l   V i r t u a l B o x   o n   t h e   P C ] ( # 1 - i n s t a l l - v i r t u a l b o x - o n - t h e - p c )  
     -   [ 2 .   I n s t a l l   U b u n t u ] ( # 2 - i n s t a l l - u b u n t u )  
     -   [ 3 .   I n s t a l l   d e p e n d e n c i e s ] ( # 3 - i n s t a l l - d e p e n d e n c i e s )  
     -   [ 4 .   C o m p i l e ] ( # 4 - c o m p i l e )  
  
 # # #   1 .   I n s t a l l   V i r t u a l B o x   o n   t h e   P C  
 F o r   i n s t a l l a t i o n   w e   s u g g e s t   V i r t u a l B o x ,   a   t o o l   t h a t   a l l o w s   y o u   t o   c r e a t e   o n e   o r   m o r e   v i r t u a l   m a c h i n e s   : c o m p u t e r : .  
 I f   a n y   o f   t h e s e   c r a s h e s ,   i n   a n y   c a s e ,   y o u r   P C   w i l l   n o t   l o s e   d a t a ,   a t   m o s t   y o u   w i l l   h a v e   t o   r e s t a r t   i t   : s m i l e : .  
  
 T o   i n s t a l l   V i r t u a l B o x   o n   y o u r   P C   y o u   n e e d   t o :  
 -   G e t   i n   i n t o   t h e   U E F I  
 -   E n a b l e   t h e   f u n c t i o n   w h i c h   n a m e   i s   l i k e   \  
 V i r t u a l i z a t i o n \   ( f o r   e a c h   U E F I   t h i s   s t e p   i s   d i f f e r e n t   b u t   s i m i l a r )  
 -   S a v e   t h e   c o n f i g u r a t i o n   a n d   r e s t a r t   t h e   P C  
 -   G o   t o   t h e   [ V i r t u a l B o x   w e b s i t e ] ( h t t p s : / / w w w . v i r t u a l b o x . o r g / )  
 -   P r e s s   \  
 D o w n l o a d \  
 -   R u n   t h e   d o w n l o a d e d   f i l e  
 -   F o l l o w   t h e   i n s t a l l a t i o n   s t e p s  
  
 # # #   2 .   I n s t a l l   U b u n t u  
 A s   t h e   O S   w e   s u g g e s t   t o   u s e   U b u n t u ,   b e c a u s e   i t   i s   l i g h t w e i g h t   ( f o r   R A M   a n d   C P U )   a n d   i t ' s   f r e e .  
  
 T o   i n s t a l l   U b u n t u   o n   V i r t u a l B o x   y o u   n e e d   t o :  
 -   D o w n l o a d   t h e   l a s t   L T S   v e r s i o n   o f   U b u n t u   b y   t h e   f o l l o w i n g   l i n k :   [ h t t p s : / / u b u n t u . c o m / d o w n l o a d / d e s k t o p ] ( h t t p s : / / u b u n t u . c o m / d o w n l o a d / d e s k t o p )  
 >   N o w   y o u   c a n   c o n t i n u e   w i t h   t h e   o t h e r   s t e p s   d u r i n g   t h e   d o w n l o a d  
 -   O p e n   V i r t u a l B o x  
 -   P r e s s   \  
 N e w \  
 -   C o m p i l e   t h e   f o r m  
         -   A s   n a m e   p u t   \  
 r e s t - c r e a t e s t r u c t u r e \  
         -   A s   T y p e :   \  
 L i n u x \  
 -   L e a v e   \  
 C r e a t e  
 a  
 v i r t u a l  
 h a r d  
 d i s k  
 n o w \   a n d   p r e s s   \ C r e a t e \  
 -   C h a n g e   t h e   h a r d   d i s k   m e m o r y ,   w e   s u g g e s t   1 6 G B   a n d   p r e s s   \  
 C r e a t e \  
 >   M a k e   s u r e   t h a t   U b u n t u   d o w n l o a d   i s   f i n i s h e d   b e f o r e   t o   c o n t i n u e  
 -   O n   t h e   V i r t u a l B o x   c o n s o l e ,   s e l e c t i n g   t h e   c r e a t e d   V M ,   p r e s s   \  
 S t a r t \  
 -   S e l e c t   a s   s t a r t - u p   d i s k   U b u n t u ,   a l r e a d y   d o w n l o a d e d  
         -   P r e s s   t h e   f o l d e r   i c o n  
         -   P r e s s   \  
 A d d \ ,   i n   t h e   t o p   m e n u  
         -   S e l e c t   t h e   U b u n t u   i s o ,   t h e   f i l e   w i l l   h a v e   a   s t r u c t u r e   l i k e   \  
 u b u n t u - v e r s i o n - o t h e r _ i n f o . i s o \  
         -   P r e s s   \  
 C h o o s e \   a n d   \ S t a r t \  
 -   F o l l o w   t h e   i n s t a l l   s t e p s   ( t h e   i n s t a l l a t i o n   n e e d s   s o m e   m i n u t e s )  
  
 # # #   3 .   I n s t a l l   d e p e n d e n c i e s  
 N o w   y o u   h a v e   t o   i n s t a l l   b u i l d i n g   d e p e n d e n c i e s .  
  
 T o   i n s t a l l   D e p e n d e s   o n   t h e   V i r t u a l   M a c h i n e   y o u   n e e d   t o :  
 -   O n   t h e   V M   ( V i r t u a l   M a c h i n e )   o p e n   t h e   t e r m i n a l   ( \ C t r l   +   A l t   +   T \ )  
  
 # # #   4 .   C o m p i l e  
 T o   c o m p i l e   t y p e :   \ ` d p k g - b u i l d p a c k a g e   - u s   - u c \ `  
  
 N o w   t h e   . d e b   f i l e   i s   i n   t h e   . . /   f o l d e r ,   y o u   c a n   i n s t a l l   i t   w i t h   a p t .  
  
 ��- - -  
 M a d e   w /   : h e a r t :   b y   C a s t e l l a n i   D a v i d e  
  
 I f   y o u   w a n t   t o   c o n t r i b u t e   y o u   c a n   s t a r t   w i t h :  
 -   [ D i s c u s s i o n ] ( / / d i s c u s s i o n s )  
 -   [ I s s u e ] ( / / i s s u e s / n e w )  
 