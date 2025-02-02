#include <iostream> // Header utama dari C Plus Plus (cin, cout, dll)
#include <cstdlib>  // Header buat menjalankan Tools Fcrackzip
#include <string>   // Header untuk menyimpan manipulasi string
#include <fstream>  // Header buat cek file ZIP dan file Wordlist

/*
Program C Plus Plus buat nge-crack kata sandi file ZIP pake Tools Fcrackzip.
Teknik yang gw pake adalah Dictionary Attack (Pake Kamus alias file Wordlist).

Dibuat oleh: Rofi (Fixploit03)

Program ini gw bikin buat eksperimen aja. OK!.

- STAY ETHIC -
*/

/*
Supaya ga pake std std an ^_^

Contohnya:

std::cout << "bla bla bla" << std::endl;
std::cin >> variabel;
*/
using namespace std;

int main(){

    // Banner program
    cout << "╔═╗╦╔═╗  ╔═╗╦═╗╔═╗╔═╗╦╔═╔═╗╦═╗" << endl;
    cout << "╔═╝║╠═╝  ║  ╠╦╝╠═╣║  ╠╩╗║╣ ╠╦╝" << endl;
    cout << "╚═╝╩╩    ╚═╝╩╚═╩ ╩╚═╝╩ ╩╚═╝╩╚═" << endl << endl;

    // Variabel untuk menampung nama file ZIP
    string nama_file_zip;
    // Variabel untuk menampung nama file Wordlist
    string nama_file_wordlist;

    // Input nama file ZIP
    cout << "[#] Masukkan nama file ZIP: ";
    getline(cin, nama_file_zip);

    // Mengecek file ZIP menggunakan ifstream
    ifstream file_zip(nama_file_zip);

    // Jika file ZIP ada
    if (file_zip){
        cout << "[+] File ZIP ditemukan." << endl;

        // Input nama file Wordlist
        cout << "[#] Masukkan nama file Wordlist: ";
        getline(cin, nama_file_wordlist);

        // Mengecekfile Wordlist menggunakan ifstream
        ifstream file_wordlist(nama_file_wordlist);

        // Jika file WOrdlist ada
        if (file_wordlist){
            cout << "[+] File Wordlist ditemukan." << endl;
            cout << "[*] Menjalankan Tools Fcrackzip..." << endl << endl;

            // Perintah menjalankan Tools Fcrackzip
            string perintah = "bin/./fcrackzip -v -u -D -p " + nama_file_wordlist + " " + nama_file_zip;
            // Menjalankan perintah
            system(perintah.c_str());
        }

        // Jika file Wordlist tidak ada
        else{
            cout << "[-] File Wordlist tidak ditemukan." << endl << endl;
        }
    }

    // Jika file ZIP tidak ada
    else{
        cout << "[-] File ZIP tidak ditemukan." << endl;
    }

    return 0;
}
