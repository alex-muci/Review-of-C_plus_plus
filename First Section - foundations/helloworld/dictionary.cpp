#include <iostream>
#include <vector>
#include <unordered_map>  // this is most common hash_table, map or dictionary in C++
#include <string>
using std::vector;
using std::cout;
using std::unordered_map;  // note this too
using std::string;


int main() {
    // Create strings to use in the hash table.
    string key = "word";
    string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
    string def_2 = "speech or talk: to express one's emotion in words";
    string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
    string def_4 = "an expression or utterance: a word of warning";
    unordered_map <string, vector<string>> my_dictionary;  // declare a map

    // Check if key is in the hash table.
    if (my_dictionary.find(key) == my_dictionary.end()) {  // If key does not exist in the map, then .find() returns an unordered_map::end() type. 
        cout << "The key 'word' is not in the dictionary." << "\n";
        cout << "Inserting a key-value pair into the dictionary." << "\n\n";
        // Set the value for the key.
        my_dictionary[key] = vector<string> {def_1, def_2, def_3, def_4};
    }

    // The key should now be in the hash table. You can access the
    // value corresponding to the key with square brackets [].
    // Here, the value my_dictionary[key] is a vector of strings.
    // We iterate over the vector and print the strings.
    cout << key << ": \n";
    auto definitions = my_dictionary[key]; // returns a C++ iterator, which is a pointer to the beginning of the iterable key-value pair.
    for (string definition : definitions) {
        cout << definition << "\n";
    }
}
