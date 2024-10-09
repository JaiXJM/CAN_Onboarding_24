# WELCOME TO CAN TEAM!!!!!!!

This directory is a small (~1.5 Hour max) intro task. There are only two functions for you to fill in, which go over two key portions of our actual CAN transmit software.

The functions you need to fill in are:
- protection_value.cpp:     protection_value
- can_threads.cpp:          process_thread

We WILL be picking the best protection_value implementation for the final system, and you NEED to complete the process_thread function to understand how to work on any thread in our actual system. 

## GETTING STARTED
To begin:

1. Open this folder in VSCode/whatever you use

2. Initialize this GIT repository (optional but recommended, you MUST learn git at some point):
- Make sure you have git installed.
- Open a terminal in this folder.
- Type `git status` into ther terminal - If it lists files, git is already tracking these files and you can skip the rest of this.
- Type `git init`` into the terminal. this creates the .git hidden folder here, and will now track any file changes. This allows you to save past versions of code.

To save this version:
- First stage your changes (tell git you want to save certain files) by typing `git add --all`` (telling git to add all files to its saving list)
- Next, type `git commit -m 'initial commit' `. commit means to save this version, and `-m` tells it to expect a message (or name/label) for this save.

## DOWNLOAD GM PROVIDED INFO FOR THE CAN TEAM
1. Create a folder on your computer that you can dump these files into!
2. Log in to autodrivechallenge.com
- Navigate to *"Jump to Activity"->"Team Capt/Member"->"Download Series Resources"* from the menu bar
- Under *"General Motors"->"Chevrolet Bolt EUV"* download the **Vehicle Integration Guide**, **Vehicle Lighting Guide**, and **BCM Lighting CPIDs guide**
- Under *"SAE International"->"Scoring Documents"* download the **Scoring CAN Message Documentation**, **Scoring Rubric**, and **Vehicle CAN Collection Guide**
- Under *"SAE International"->"AutoDrive Rules"* download the **AutoDrive Challenge II - Year 4 Ruleset**
3. Unzip any zip folders and make sure you can access the contents

## PART 1
In this part, you will code a function that calculates the Protection Value of a given integer at a given rolling count. 
Your input is three `int` values:
- `to_encode`: The original data to encode. (HINT: Though it is passed in as an int, think of it in binary when coding this)
- `rolling_count`: An int representation of the Rolling Count, which can range from 0 - 3 inclusive.
- `length` : The length of to_encode in bits (HINT: There is one case where this should not be the length of your output)

Your output is one `int` value, corresponding to the integer representation of the binary protection value.


The protection value process can be found in the **Vehicle Integration Guide** at the end of the Steering, Braking, or Propulsion PDFs.

### Here is an example:

`0000 1011` or 11, is passed in as encode

`10` or 2, is the rolling count

**8** is the length of the input in bits (and thus should be the output length)

1. Addition:

Add the rolling count to to_encode.
`0000 1011` + `10` = `0000 1101`

2. Inverse:

Take the inverse of all bits that are within the output length
`0000 1011` -> `1111 0100`

3. Add 1:

Add '1' to the inverted value
`1111 0101`

Final Notes: 
- The protection value should always have the same length as the longest input (including rolling count, which always has a length of 2)
- Your code should set all bits above this length to 0.

## PART 2

