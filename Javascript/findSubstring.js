// Github username: Meekunn
// Aim: 
/*
Finding the longest substring that contains k unique characters, where k is the first character from the string 
Input 1: 2aabbacbaa, Output 1: aabba
Input 2: 2aabbcbbbadef, Output 2: bbcbbb
*/
// Date: 04-10-2022

let MAX_CHAR = 26;
let A_ASCII = 97;

function isValid(alphabets_freq, k){
	let c = 0;
	for(let i = 0; i < MAX_CHAR; i++)
		if(alphabets_freq[i] > 0) c++;
	return (k >= c);
}

function SearchingChallenge(str){
	let string = str.substr(1, str.length - 1);

	let alphabets_freq = Array(MAX_CHAR).fill(0);
	let k = parseInt(str[0]), first_pointer = 0, second_pointer = 0, MAX_window_size = 1, MAX_window_pointer = 0;

	alphabets_freq[string[0].charCodeAt(0) - A_ASCII]++;

	for(let i = 1; i < string.length; i++){
		alphabets_freq[string[i].charCodeAt(0) - A_ASCII]++;
		second_pointer++;

		while(!isValid(alphabets_freq, k)){
			alphabets_freq[string[first_pointer].charCodeAt(0) - A_ASCII]--;
			first_pointer++;
		}

		if(second_pointer - first_pointer + 1 >= MAX_window_size){
			MAX_window_size = second_pointer - first_pointer + 1;
			MAX_window_pointer = first_pointer;
		}
	}

	return string.substr(MAX_window_pointer, MAX_window_size);
}

console.log("Input: 2aabbacbaa, Output: " + SearchingChallenge("2aabbacbaa"));
console.log("Input: 2aabbcbbbadef, Output: " + SearchingChallenge("2aabbcbbbadef"));
