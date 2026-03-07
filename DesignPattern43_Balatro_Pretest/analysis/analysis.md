PART A — Creational Pattern Analysis

A1 — Factory
Where are modifier objects created?
Modifier dibuat di kelas ModifierFactory, di fungsi CreateModifier(std::string modifierName).

Memusatkan pembuatan menguntungkan karena kelas lain tidak perlu tau proses pembuatan modifier secara spesifik. Ini membuat kode nya tidak saling bergantung dan mudah dipolar.

A2 — Extensibility
Explain how you added SquareScoreModifier.
Membuat file SquareScoreModifier.h dan SquareScoreModifier.cpp yang akan mewarisi IModifier.

Lalu menambahkan kondisi if (modifierName == "SquareScore") di ModifierFactory.cpp. Setelah itu memperbarui interface teks di ShopSystem.cpp agar pemain bisa membelinya. 

Desainnya mudah diperluas karena tidak perlu mengubah inti permainan atau penghitung skor.

A3 — Factory Method (Conceptual)
If you had multiple shop types, how would Factory Method help?
Provide example interface.
Factory Method memungkinkan untuk membuat interface IShop yang memiliki fungsi CreateShopItems(). Setiap jenis toko akan memiliki implementasinya sendiri untuk memproduksi modifier berbeda.

class IShop {
public:
    virtual std::vector<IModifier*> CreateShopItems() = 0;
};

A4 — Prototype (Conceptual)
Explain how Clone() could help duplicate modifiers.
Where would Clone() be implemented?
Jika pemain membeli item yang bisa menggandakan modifier, panggil modifier->Clone().

Fungsi ini dideklarasikan sebagai virtual IModifier* Clone() = 0; di file IModifier.h, dan diimplementasikan secara spesifik di setiap kelas turunannya.

A5 — Singleton (Conceptual)
Did you use global objects?
Explain advantages and risks.
Saya tidak menggunakan global objek, data pemain disimpan di objek Player yang disalurkan ke kelas lain.

Kelebihan Singleton : memudahkan akses ke system inti dari mana saja tanpa harus melempar referensi berulang kali.
Resiko Singleton : Membuat status global sulit dilacak. Jika ada bug skor berubah tiba-tiba, akan sulit mencari mana kelas yang mengubahnya karena semua kelas punya akses ke objek global tersebut.

PART B — Structural Pattern Analysis

B1 — Decorator Concept
Explain how your modifier system behaves like a Decorator pattern. What is being decorated?
Sistem modifier ini berperilaku seperti decorator karena setiap modifier membungkus dan memodifikasi nilai yang dihasilkan oleh modifier sebelumnya tanpa mengubah struktur aslinya.

for (IModifier* mod : tasPemain) {
    currentScore = mod->ApplyModifier(currentScore);
}

B2 — Modifier Order
Does modifier order affect score?
Explain example using your code.
Iya, urutan modifier sangat mempengaruhi hasil akhir. Modifier dieksekusi berdasarkan urutan pembelian.

Dalam file Player.h, modifier disimpan dalam wadah std::vector::<IModifier*> activeModifiers. Saat pemain membeli modifier baru menggunakan fungsi AddModifier(), item tersebut ditambahkan ke urutan paling belakang (push_back).

Lalu di ScoringSystem.cpp, loop for (IModifier* mod : tasPemain) mengeksekusi modifier secara berurutan dari urutan pertama hingga terakhir.

Contoh :
Jika baseScore adalah 10.
 - Jika pemain membeli RandomBonus (+50) lalu TripleScoreModifier (x3), perhitungan di dalam loop menjadi : (10 + 50) * 3 = 180.
 - Jika urutan belinya dibalik menjadi TripleScoreModifier lalu RandomBonus, perhitungannya menjadi : (10 * 3) + 50 = 80.

B3 — Composite (Conceptual)
Explain how a modifier group could be implemented.
Kita bsia membuat kelas ModifierGroup yang mewarisi interface Imodifier. Dalam kelas ini, kita menyimpan kumpulan modifier menggunakan std::vector<IModifier*>. Saat fungsi ApplyModifier() dipanggil, ia akan melakukan looping untuk memanggil fungsi ApplyModifier() milik semua modifier anak di dalamnya secara berurutan.

B4 — Adapter (Conceptual)
Explain how you would integrate an external scoring system using Adapter.
Saya akan membuat kelas misal: PokerAdapter yang mewarisi IScoringSystem. 

B5 — Facade (Conceptual)
Design a GameFacade class for your system.
What functions would it expose?
GameFacade akan membungkus kerumitan RunSession, Deck, ShopSystem, dan HandEvaluator sehingga interface utama (main.cpp) menjadi sangat bersih. Fungsi yang akan diekspos :

 - void InitializeGame() menyiapkan Player dan Deck
 - void PlayRound() menjalankan alur Draw, PlayHand, Evaluate dan Scoring
 - void EnterShopPhase() mengatur perpindahan ke UI shop

PART C — Behavioral Pattern Analysis
C1 — Strategy
Explain where scoring logic exists.
How would you support multiple scoring rules?
Logika skoring terbagi jadi dua: penentuan nilai dasar kombo poker ada di HandEvaluator::EvaluateHand(), sementara penerapan perhitungan modifier ada di ScoringSystem::CalculateBaseScore().

C2 — Observer (Conceptual)
Identify events in your system.
Explain how Observer could improve design.

C3 — Command (Conceptual)
Identify actions that could be represented as Command objects.
Beberapa contoh Tindakan pemain yang cocok untuk diubah menjadi command adalah:
 - Tindakan memainkan kartu PlayHandCommand
 - Tindakan membeli toko di barang BuyModifierCommand
 - Tindakan membuang kartu dari tangan DiscardCommand

C4 — State (Conceptual)
Explain how State pattern could organize run phases.
