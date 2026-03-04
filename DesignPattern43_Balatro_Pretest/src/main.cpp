#include "RunSession.h" // Memanggil file header RunSession.h
#include <iostream>

int main()
{
  // 1. Membuat "wujud nyata" (objek) dari cetak biru RunSession
  RunSession gameSession;

  // 2. Menyalakan mesin permainannya
  gameSession.RunLoop();

  return 0;
}