#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string s, char c) {
    std::string current;
    std::vector<std::string> v;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c) {
            current += s[i];
        }
        else {
            v.push_back(current);
            current = "";
        }
    }
    v.push_back(current);
    return v;
}

std::string readFile(std::string path) {
    std::string line, result;
    std::ifstream file(path);
    if (file.is_open()) {
        while ( getline(file, line) ) {
            result += line + ' ';
        }
        file.close();
    } 

    else {
        std::cout << "Unable to open file"; 
        exit(1);
    }
    return result;
}

void writeFile(std::string path, std::string data) {
    std::string line, result;
    std::ofstream file(path);
    if (file.is_open()) {
        file << data;
        file.close();
    } 

    else {
        std::cout << "Unable to open file"; 
        exit(1);
    }
}

std::string registers(std::string reg) {
    if (reg == "R0") return "0000 ";
    else if (reg == "R1") return "0001 ";
    else if (reg == "R2") return "0002 ";
    else if (reg == "R3") return "0003 ";
    else if (reg == "R4") return "0004 ";
    else if (reg == "R5") return "0005 ";
    else if (reg == "R6") return "0006 ";
    else if (reg == "IP" || reg == "OU") return "0007 ";
    else if (reg == "DIS") return "0008 ";
    else {
        std::cout << "ERROR";
        return "E";
    }
}


int main(int argc, char* argv[]) {
    /*if (argc < 2) {
        std::cout << "Error, not file given.\n";
        exit(1);
    }*/

    std::string code = readFile("code.alt");
    std::vector<std::string> v = split(code, ' ');
    std::string result;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "") {
            continue;
        }
        else if (v[i] == "NOOP") {
            result += "0000 0000 0000 0000\n";
        }
        else if (v[i] == "MOV") {
            result += "0001 "; // MOV
            i++;
            result += registers(v[i]); // R1
            result += "0000 ";
            i++;
            result += registers(v[i]) + "\n"; // R2
        }
        else if (v[i] == "IMM") {
            result += "0002 ";
            i++;
            result += v[i] + " ";
            result += "0000 ";
            i++;
            result += registers(v[i]) + "\n";
        }
        else if (v[i] == "PUSH") {
            result += "0003 ";
            i++;
            result += registers(v[i]);
            result += "0000 0000\n";
        }
        else if (v[i] == "POP") {
            result += "0004 ";
            result += "0000 0000 ";
            i++;
            result += registers(v[i]) + "\n";
        }
        else if (v[i] == "RESET") {
            result += "0005 ";
            i++;
            result += registers(v[i]);
            result += "0000 0000\n";
        }
        else if (v[i] == "ADD") {
            result += "0006 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "SUB") {
            result += "0007 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "AND") {
            result += "0008 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "OR") {
            result += "0009 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "NAND") {
            result += "000a ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "NOR") {
            result += "000b ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "XOR") {
            result += "000c ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "XNOR") {
            result += "000d ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "NOT") {
            result += "000e ";
            i++;
            result += registers(v[i]);
            result == "0000 ";
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "SHR") {
            result += "000f ";
            i++;
            result += registers(v[i]);
            result += "0000 ";
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "SHL") {
            result += "0010 ";
            i++;
            result += registers(v[i]);
            result += "0000 ";
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "IGT") {
            result += "0011 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "IEQ") {
            result += "0012 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "INEQ") {
            result += "0013 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "ILT") {
            result += "0014 ";
            i++;
            result += registers(v[i]);
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "ADDi") {
            result += "0015 ";
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "SUBi") {
            result += "0016 ";
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += registers(v[i]) + '\n';
        }
        else if (v[i] == "IGTi") {
            result += "0017 ";
            i++;
            result +=  registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "IEQi") {
            result += "0018 ";
            i++;
            result +=  registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "INEQi") {
            result += "0019 ";
            i++;
            result += registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "ILTi") {
            result += "001a ";
            i++;
            result +=  registers(v[i]);
            i++;
            result += v[i] + ' ';
            i++;
            result += v[i] + '\n';
        }
        else if (v[i] == "JMP") {
            result += "001b ";
            result += "0000 0000 ";
            i++;
            result += v[i] + '\n';
        }
        else {
            result += "ERROR";
        }
    }
    std::cout << result;
}