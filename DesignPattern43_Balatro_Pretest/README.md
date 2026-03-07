## Architecture Overview
* **`main.cpp`**: Titik masuk program yang menginisiasi permainan.
* **`RunSession`**: Mengatur *game loop* utama hingga masuk ke toko. 
* **`Player`**: Menyimpan status pemain seperti uang, kartu di tangan, dan koleksi *modifier* aktif yang sudah dibeli.
* **`Deck` & `Card`**: Mengelola tumpukan kartu dan pembagian kartu acak ke pemain.
* **`HandEvaluator`**: Bertindak sebagai juri untuk membaca kombinasi kartu dan menentukan skor dasar.
* **`ScoringSystem`**: Menghitung skor akhir dengan mengaplikasikan seluruh *modifier* milik pemain ke skor dasar.
* **`ShopSystem`**: Menampilkan *interface* toko tempat pemain bisa membeli *modifier*.
* **`ModifierFactory`**: Pabrik pembuat objek *modifier* agar pembuatan *item* terpusat.

## Pattern Usage
* **Creational Pattern (Factory)**: Diimplementasikan pada `ModifierFactory`. Kelas ini menyembunyikan logika pembuatan objek dari `ShopSystem` agar toko hanya perlu mengirimkan nama *string*, dan pabrik akan membuat objek yang sesuai.
* **Structural Pattern (Decorator Concept)**: Diimplementasikan pada eksekusi *modifier* di `ScoringSystem`. Setiap *modifier* yang mewarisi *interface* `IModifier` secara dinamis membungkus skor dan memodifikasinya secara berurutan tanpa mengubah logika intinya.
* **Behavioral Pattern (Strategy Concept)**: Diimplementasikan dengan memisahkan dua logika perhitungan: Penentuan nilai kombo dilakukan oleh `HandEvaluator`, sedangkan eksekusi perhitungannya dilakukan oleh `ScoringSystem`.

## Modification Log
* **Awal penambahan:** Saya awalnya membuat `SquareScoreModifier.h` dan `SquareScoreModifier.cpp` yang mewarisi `IModifier`. Objek ini ditambahkan ke `ModifierFactory` dan menu `ShopSystem`.
* **Masalah:** Saat diuji coba, mengalikan skor dengan pangkat dua menyebabkan *Integer Overflow* pada variabel `int` yang membuat hasilnya menjadi minus.
* **Refactoring/Balancing:** Untuk menjaga keseimbangan *gameplay* dan mencegah *error* tipe data, saya mengubah tipe datanya menjadi `long long` dan merevisi `SquareScoreModifier` menjadi `TripleScoreModifier`. Semua referensi nama di pabrik dan toko diubah ke nama yang baru.

## AI Usage Disclosure
* Semua pembuatan *code* dibantu oleh AI.
* AI juga membantu menjelaskan *code-code* yang tidak saya mengerti untuk menjawab pertanyaan-pertanyaan pada *pre-test*.
* Membantu merapihkan format README.md
