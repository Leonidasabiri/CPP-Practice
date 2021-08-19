#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// This is a codwares challenge called simple assembly interpreter, it was good for practicing c++
// P.S : Still didn't make the jnz instruction functionality so this code does not pass the test cases,.. but the instructions mov, inc, dec,..function properly
// I pushed it just to not lose my progress on this kata

using namespace std;

unordered_map<string, int> assembler(vector<string>& program)
{
    unordered_map<string, int> dict;
    vector<string> strings, regStrings, registerVar;
    stringstream regvalues, stepValue;
    int regVal = 0;
    int stepsRepeating;

    for (unsigned long i = 0; i < program.size(); i++) // Looping the entire string array to parse the instructions
    {
        stringstream ss(program[i]);
        vector<string> instructions((istream_iterator<string>(ss)), istream_iterator<string>()); // A way to split strings based on whitesapaces
        strings.push_back(instructions[0]);       // Making a list of registers variables name
        if (strings[i] == "mov")
        {
            registerVar.push_back(instructions[1]);
            regStrings.push_back(instructions[2]);
        }
    }
    for (unsigned long j = 0; j < strings.size(); j++)
    {
        stringstream s(program[j]);
        vector<string> v((istream_iterator<string>(s)), istream_iterator<string>()); // Parse the register variables so that they can hold there values
        if (strings[j] == "mov")
        {
            try 
            {
                regVal = stoi(regStrings[j]); // Convert the register string number into an int
                dict[registerVar[j]] = regVal;
            }
            catch (exception &e) // Catch the exception if the register is trying to get the value of another register
            {
                regVal = dict[regStrings[j]];
                dict[registerVar[j]] = regVal;
            }
        }
        else if (strings[j] == "inc")
        {
            regVal = dict[v[1]];
            regVal++;
            dict[v[1]] = regVal;
        }
        else if (strings[j] == "dec")
        {
            regVal = dict[v[1]];
            regVal--;
            dict[v[1]] = regVal;
        }
        else if (strings[j] == "jnz")
        {
            stepsRepeating = stoi(regStrings[j]);
        }
    }
    return dict;
}

// Overloading the input stream operator to print the keys and values of the dictionary
template<typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& m)
{
    for (const pair<K, V>& p : m)
        os << p.first << " " << p.second << endl;
    return os;
}

int main()
{
    //The string array of the instructions to be parsed (these default strings gives: b 3, c 3, e 0,...you can change them ofc)
    vector<string> program{ "mov b 3",
                            "mov c -123",
                            "mov c 2",
                            "mov e 1",
                            "inc c",
                            "dec e" };
    unordered_map<string, int> dict = assembler(program);
    cout << dict;
}