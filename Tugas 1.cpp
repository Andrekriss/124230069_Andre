#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Film {
    string judul;
    int kode;
    float rating;
};

// Fungsi untuk menampilkan film
void displayFilms(vector<Film>& films) {
    for (const auto& film : films) {
        cout << "Judul: " << film.judul << ", Kode: " << film.kode << ", Rating: " << film.rating << endl;
    }
}

// mencari film berdasarkan kode
void sequentialSearch(vector<Film>& films, int code) {
    for (const auto& film : films) {
        if (film.kode == kode) {
            cout << "Film ditemukan: Judul: " << film.judul << ", Kode: " << film.kode << ", Rating: " << film.rating << endl;
            return;
        }
    }
    cout << "Film dengan kode " << kode << " tidak ditemukan." << endl;
}

// mencari film berdasarkan judul menggunakan binary search
void binarySearch(vector<Film>& films, string title) {
    sort(films.begin(), films.end(), [](Film a, Film b) { return a.title < b.title; });
    int left = 0, right = films.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (films[mid].title == title) {
            cout << "Film ditemukan: Judul: " << films[mid].judul << ", Kode: " << films[mid].code << ", Rating: " << films[mid].rating << endl;
            return;
        }
        if (films[mid].judul < judul) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Film dengan judul " << judul << " tidak ditemukan." << endl;
}

// Mengurutkan film berdasarkan rating secara ascending menggunakan Quick sort)
void quickSort(vector<Film>& films, int low, int high) {
    if (low < high) {
        int pivot = partition(films, low, high);
        quickSort(films, low, pivot - 1);
        quickSort(films, pivot + 1, high);
    }
}

int partition(vector<Film>& films, int low, int high) {
    float pivot = films[high].rating;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (films[j].rating <= pivot) {
            i++;
            swap(films[i], films[j]);
        }
    }
    swap(films[i + 1], films[high]);
    return i + 1;
}

// Mengurutkan film berdasarkan Rating secara descending menggunakan Bubble Sort
void bubbleSort(vector<Film>& films) {
    for (size_t i = 0; i < films.size() - 1; i++) {
        for (size_t j = 0; j < films.size() - i - 1; j++) {
            if (films[j].rating < films[j + 1].rating) {
                swap(films[j], films[j + 1]);
            }
        }
    }
}

int main() {
    vector<Film> films = {
        {"Komedi", 101, 8.5},
        {"Action", 102, 7.2},
        {"Romance", 103, 9.1},
        {"Horror", 104, 6.8}
    };

    cout << "Semua data film:" << endl;
    displayFilms(films);

    cout << "\nMencari film berdasarkan kode (misalnya: 102):" << endl;
    sequentialSearch(films, 102);

    cout << "\nMencari film berdasarkan judul (misalnya: Film B):" << endl;
    binarySearch(films, "Film B");

    cout << "\nMengurutkan film berdasarkan rating secara ascending menggunakan Quick Sort:" << endl;
    quickSort(films, 0, films.size() - 1);
    displayFilms(films);

    cout << "\nMengurutkan film berdasarkan rating secara descending menggunakan Bubble Sort:" << endl;
    bubbleSort(films);
    displayFilms(films);

    return 0;
}
