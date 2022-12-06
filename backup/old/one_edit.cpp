/*
Sample Problem 
Write a function to return if two words are exactly "one edit" away, where an edit is:
	Inserting one character anywhere in the word (including at the beginning and end)
	Removing one character
    Replacing exactly one character

Assuming only alphabets in input strings
Assuming string length < 100
empty string acceptable as input

How to tackle the problem
manually checking all possible one edits and compare
    inefficient
word can be decomposed into a data structure of characters
can it address all three cases?
    when the legnths of two strings are the same, then only #3 can hold
    when the lengths of two strings are different, only #1 and #2 can hold.
Aren't #1 and #2 essentially the same?
    both occur when one word has one more character than the other
    when #1 is true, one word has an extra character somewhere, and removing that one character does the same thing.

we should begin by getting the lengths of the strings
    if differs by exactly one, check #1,#2
    else if same, then check #3
    else return false

how can we check #1 and #2
    iterate through the shorter string matching the characters to the longer string
    if there is a mismatch, 
        skip a character on the longer string and contiue
    if there is a second mismatch, return false
    if end is reached without a mismatch, return true
        (because we already checked for length, the longer string is guaranteed to have an extra character that can be removed)

how can we check #3
    iterate through the strings matching the characters to the longer string
    if there is a mismatch,
        flag it and move to the next
        if there was a previous mismatch,return false
    if there was no mismatch, return false (it has to be exactly one edit)
    if there was one mismatch, return true
*/

#include <string>
#include <iostream>

bool one_edit_away(std::string first, std::string second) {
    int len_first = first.length();
    int len_second = second.length();

    if (len_first == len_second) {
        // check #3 here
        int num_mismatch = 0;

        for (int i = 0; i < len_first; i++) {
            if (first[i] != second[i]) {
                num_mismatch++;
                if (num_mismatch > 1) {
                    return false;
                }
            }
        }
        if (num_mismatch == 0) {
            return false;
        }
        return true;
    }
    else {
        std::string larger;
        std::string smaller;
        int len_smaller;
        int diff;

        if (len_first > len_second) {
            larger = first;
            smaller = second;
            diff = len_first - len_second;
            len_smaller = len_second;
        } else { // len_second > len_first
            larger = second;
            smaller = first;
            diff = len_second - len_first;
            len_smaller = len_first;
        }

        if (diff != 1) {
            return false;
        }

        //Check #1#2 here
        int num_mismatch = 0;
        int idx_s = 0;
        int idx_l = 0;

        while (idx_s < len_smaller) {
            if (smaller[idx_s] != larger[idx_l]) {
                num_mismatch++;
                if (num_mismatch > 1) {
                    return false;
                }
                idx_l++;
                if (smaller[idx_s] != larger[idx_l]) {
                    return false;
                }
            }
            idx_s++;
            idx_l++;
        }
        return true;
    }
}
    

int main(void) {
    int num_cases;
    std::string first;
    std::string second;

    std::cin >> num_cases;

    while (num_cases--) {
        std::cin >> first;
        std::cin >> second;
        std::cout << one_edit_away(first,second) << std::endl;
    } 
    return 0;
}
