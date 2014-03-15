Hash Cracker Version 2
===================

I thought that my previous version of Python MD5 hash cracker had become a little old so decided to do a new one in C++. It includes some new features and for now it supports MD5 but will be adding SHA-1 and other dictionary attack vulnerable hashes. Also I've added OS compatibility for MAC OSX, Linux and Windows which I think was limited to only one OS in my previous version.

Features:
=======

1) Faster Cracking<br />
2) Introduced a new feature to store cracked hashes automatically in a text file so next time if the same hash come's around you will be prompted that this hash has been cracked already and the password is.<br />
3) OS Support added for Linux, MAC OSX, Windows (32bit & 64bit)<br />
4) Will support more hashes (MD5 for now)<br />

How to Crack:
===========
1) Compile the Hash Cracker<br />
2) Put the dictionary file in it's directory (Compiled)<br />
3) Choose option 1 to load dictionary and enter your file name, You will be prompted if it's wrong.<br />
4) Next, Choose option 2 from the menu and enter your MD5 hash.<br />
5) Choose option 3<br />
6) If you are not prompted with anything during the cracking process, it means that no suitable match case was found in your dictionary<br />

For any suggestions or improvements, contact me :)
