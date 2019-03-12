#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, string> dict;
int n;

string opcode, rd, ra, rb;
string to_hex[] = { "0000","0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
int sc;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dict["ADD"] = "000000";
	dict["ADDC"] = "000010";
	dict["SUB"] = "000100";
	dict["SUBC"] = "000110";
	dict["MOV"] = "001000";
	dict["MOVC"] = "001010";
	dict["AND"] = "001100";
	dict["ANDC"] = "001110";
	dict["OR"] = "010000";
	dict["ORC"] = "010010";
	dict["NOT"] = "010100";
	dict["MULT"] = "011000";
	dict["MULTC"] = "011010";
	dict["LSFTL"] = "011100";
	dict["LSFTLC"] = "011110";
	dict["LSFTR"] = "100000";
	dict["LSFTRC"] = "100010";
	dict["ASFTR"] = "100100";
	dict["ASFTRC"] = "100110";
	dict["RL"] = "101000";
	dict["RLC"] = "101010";
	dict["RR"] = "101100";
	dict["RRC"] = "101110";
	dict["0"] = "000";
	dict["1"] = "001";
	dict["2"] = "010";
	dict["3"] = "011";
	dict["4"] = "100";
	dict["5"] = "101";
	dict["6"] = "110";
	dict["7"] = "111";


	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> opcode >> rd >> ra;
		cout << dict[opcode] << dict[rd] << dict[ra];
		if (dict[opcode][4] == '0') {
			cin >> rb;
			cout << dict[rb] << '0';
		}
		else {
			cin >> sc;
			cout << to_hex[sc];
		}
		cout << '\n';
	}
	return 0;
}