#pragma once

class IModifier {
public:
  // Fungsi ini wajib dimiliki oleh semua wujud nyata kartu modifier nanti
  virtual int ApplyModifier(int currentScore) = 0;

  // Ini adalah pelengkap wajib di C++ agar memori aman saat menghapus objek
  virtual ~IModifier() {}
};