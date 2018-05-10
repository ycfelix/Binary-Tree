#include <iostream>
#include <string>
#include <sstream>
#include "BST.h"
#include "BSTExercises.h"
using namespace std;

/*
 * 	 **** You should not modify this function! ****
 *   Inputs
 *   (1) bst		    : The BST shown in the lab page. You need to build this in main().
 *   (2) encoded_message: A series of morse code symbols. Each word is separated by a '/', and each character is separated by a ' '.
 *   (3) word_delim     : The delimiter of words.
 *   (4) char_delim     : The delimiter of characters.
 *
 *   Output
 *   The decoded message.
 */
string decode_message(const BST<int, char>& bst, const string& encoded_message, char word_delim='/', char char_delim=' ') {
	// Example: The original message is "AB CD".
	//      	A => .-
	// 			B => -...
	// 		   AB => .- -...
	//          C => -.-.
	//          D => -..
	// 		   CD => -.-. -..
	// 		AB CD => .- -.../-.-. -..
	// 			Then, the encoded message is ".- -.../-.-. -..".

	stringstream ss(encoded_message);
	string decoded_message, symbols, symbol;
	while (getline(ss, symbols, word_delim)) {
		// Here we split the encoded_message by '/'. In the first iteration,  symbols = ".- -..."
		//											 In the second iteration, symbols = "-.-. -.."
		stringstream ss_(symbols);
		while (getline(ss_, symbol, char_delim))
			// Here we split the symbols by ' '.
			// The variable symbol will be the morse code symbols (i.e., ".-", "-...", "-.-.", "-..") in the encoded_message,
			// and you are going to decode it in the following line.
			decoded_message += decode(bst, symbol);
		decoded_message += ' ';
	}
	return decoded_message;
}


int main() {
	cout << "======================================" << endl;
	cout << "Part A: Implementation" << endl;
	cout << "======================================" << endl;

	BST<int, char> bst_a;
	cout << "Tree:" << endl;
	bst_a.print();
	cout << boolalpha << "isBalanced : " << isBalanced(bst_a) << endl;
	cout << "diameter : " << diameter(bst_a) << endl;
	cout << "**************************************" << endl;

	bst_a.insert(5, 'a');
	bst_a.insert(10, 'b');
	cout << "Tree:" << endl;
	bst_a.print();
	cout << boolalpha << "isBalanced : " << isBalanced(bst_a) << endl;
	cout << "diameter : " << diameter(bst_a) << endl;
	cout << "**************************************" << endl;

	bst_a.insert(15, 'c');
	bst_a.insert(2, 'd');
	cout << "Tree:" << endl;
	bst_a.print();
	cout << boolalpha << "isBalanced : " << isBalanced(bst_a) << endl;
	cout << "diameter : " << diameter(bst_a) << endl;
	cout << "**************************************" << endl;

	bst_a.insert(30, 'e');
	bst_a.insert(3, 'f');
	bst_a.insert(1, 'g');
	bst_a.insert(0, 'h');

	cout << "Tree:" << endl;
	bst_a.print();
	cout << boolalpha << "isBalanced : " << isBalanced(bst_a) << endl;
	cout << "diameter : " << diameter(bst_a) << endl;


	cout << endl << endl;
	cout << "======================================" << endl;
	cout << "Part B: Morse Code Decoder " << endl;
	cout << "======================================" << endl;
    BST<int, char> bst_b;

	/****** START YOUR IMPLEMENTATION FOR PART B1 HERE ******/
    char tree[28] = {'*','E','T','I','A','N','M','S','U','R','W','D','K','G','O','H','V','F','L','P','J','B','X','C','Y','Z','Q'};
    int list[]={14,7,22,4,10,18,26,2,6,9,12,16,20,24,27,1,3,5,8,11,13,15,17,19,21,23,25};
    for(int i=0;i<27;i++)
    {
    	bst_b.insert(list[i], tree[i]);
    }





	/******* END YOUR IMPLEMENTATION FOR PART B1 HERE *******/
    bst_b.print();
	cout << boolalpha << "isBalanced : " << isBalanced(bst_b) << endl;
	cout << "diameter : " << diameter(bst_b) << endl << endl;

    string message_1("- .... .. .../.. .../- .... ./.-.. .- ... -/.-.. .- -.../.. -./- .... .. .../-.-. --- ..- .-. ... .");
    cout << decode_message(bst_b, message_1) << endl;

    string message_2("- .... .- -. -.-/-.-- --- ..-/... ---/-- ..- -.-. ....");
	cout << decode_message(bst_b, message_2) << endl;

	string message_3("--. --- --- -../.-.. ..- -.-. -.-/.-- .. - ..../-.-- --- ..- .-./. -..- .- -- ...");
	cout << decode_message(bst_b, message_3) << endl;

}
