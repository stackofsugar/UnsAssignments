#include <stdio.h>

struct Barang {
	int Wajan, Saring, Panci, Sun, Minyak, Rinso, Sendok, Garpu, Promo1, Promo2, Promo3, Promo4;
};

int perhitungan (int *a, int *harga) {
	int i = 0, t = 0;
	while (i < *a) {
		t += *harga;
		i++;
	}

	return t;
}

int total1 (int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *i, int *j, int *k, int *l) {
	int total = 0;
	total = *a + *b + *c + *d + *e + *f + *g + *h + *i + *j + *k + *l;
	
	return total;
}

int total2 (int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *i, int *j, int *k, int *l) {
	float sum = 0, diskon, total = 0;
	
	sum = *a + *b + *c + *d + *e + *f + *g + *h + *i + *j + *k + *l;
	diskon = sum * (0.2);
	total = sum - diskon;
	
	return total;
}

int main () {

	struct Barang jumlah = {0,0,0,0,0,0,0,0,0,0,0,0};
	int pilih, kode, kode1, uang, metode, nota, harga[12]={30000, 3000, 20000, 12000, 12000, 15000, 1500, 1500, 40000, 45000, 28000, 90000};
	int twajan, tsaring, tpanci, tsun, tminyak, trinso, tsendok, tgarpu, tpromo1 = 0, tpromo2 = 0, tpromo3 = 0, tpromo4 = 0;
	
	printf("\t\t\t\t\t%s\n\t\t\t\t\t   Selamat Datang di Toko Kami\n\t\t\t\t\t%s\n\n", "================================", "================================");
	printf("\t\t\t  Silahkan berbelanja kebutuhan rumah tangga yang diperlukan\n\t\t\t\t\t   Dijamin murah dan meriah!!!\n\n");
	printf("\t\t  Khusus tahun ini, gunakan kartu member untuk mendapatkan diskon sebesar 20%%.\n\t\t\t\t  Kami juga memiliki promo bulan ini. Tertarik?\n\n");
	
	list:
		printf("\n  Barang yang saat ini tersedia:\n");
		printf("   1. Wajan\t\t\t-> Rp 30.000\t\t6. Rinso Detergen Cair Anti Noda 750 ml\t-> Rp 15.000\n   2. Saringan\t\t\t-> Rp 3.000\t\t7. Sendok\t\t\t\t-> Rp 1.500\n   3. Panci\t\t\t-> Rp 20.000\t\t8. Garpu\t\t\t\t-> Rp 1.500\n   4. Sunlight Lemon 800 ml\t-> Rp 12.000\t\t9. Promo\n   5. Minyak Kelapa Sawit 1L\t-> Rp 12.000\n\n");
		printf("  Silahkan memasukan kode barang yang ingin dibeli: ");
		scanf("%d", &kode);
	
		if (kode == 1) {
			wajan:
				printf("  Masukan jumlah wajan yang ingin dibeli: ");
				scanf("%d", &jumlah.Wajan);
					if (jumlah.Wajan < 0) {
						printf("  Maaf, tolong ulangi lagi\n");
						goto wajan;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}	
		} else if (kode == 2) {
			saringan:
				printf("  Masukan jumlah saringan yang ingin dibeli: ");
				scanf("%d", &jumlah.Saring);
					if (jumlah.Saring < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto saringan;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 3) {
			panci:
				printf("  Masukan jumlah panci yang ingin dibeli: ");
				scanf("%d", &jumlah.Panci);
					if (jumlah.Panci < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto panci;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 4) {
			sunlight:
				printf("  Masukan jumlah sunlight yang ingin dibeli: ");
				scanf("%d", &jumlah.Sun);
					if (jumlah.Sun < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto sunlight;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 5) {
			minyak:
				printf("  Masukan jumlah minyak yang ingin dibeli: ");
				scanf("%d", &jumlah.Minyak);
					if (jumlah.Minyak < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto minyak;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 6) {
			rinso:
				printf("  Masukan jumlah rinso yang ingin dibeli: ");
				scanf("%d", &jumlah.Rinso);
					if (jumlah.Rinso < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto rinso;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 7) {
			sendok:
				printf("  Masukan jumlah sendok yang ingin dibeli: ");
				scanf("%d", &jumlah.Sendok);
					if (jumlah.Sendok < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto sendok;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 8) {
			garpu:
				printf("  Masukan jumlah garpu yang ingin dibeli: ");
				scanf("%d", &jumlah.Garpu);
					if (jumlah.Garpu < 0) {
						printf("Maaf, tolong ulangi lagi\n");
						goto garpu;
					}
				printf("  Ingin berbelanja lagi?\n   1. Ya\t2. Tidak\n");
				printf("  Pilihan: ");
				scanf("%d", &pilih);
					if (pilih == 1) {
						goto list;
					} else if (pilih == 2) {
						goto hitung;
					}
		} else if (kode == 9) {
			promo:
				printf("   Promo:\n    1. 2 Wajan\t\t\t-> Rp 40.000\n    2. 3 Panci\t\t\t-> Rp 45.000\n    3. 2 Minyak Kelapa Sawit\t-> Rp 28.000\n       Gratis 1 Sunlight Lemon\n    4. 4 Panci Gratis 1 Wajan\t-> Rp 90.000\n    5. Back\n\n");
				printf("    Masukan kode promo: ");
				scanf("%d", &kode1);
					if (kode1 == 1) {
						jumlah.Promo1 = 1;
						tpromo1 = harga[8];
					} else if (kode1 == 2) {
						jumlah.Promo2 = 1;
						tpromo2 = harga[9];
					} else if (kode1 == 3) {
						jumlah.Promo3 = 1;
						tpromo3 = harga[10];
					} else if (kode1 == 4) {
						jumlah.Promo4 = 1;
						tpromo4 = harga[11];
					} else if (kode1 == 5) {
						goto list;
					} else {
						printf("    Maaf, promo hanya ada 4!\n    Ingin berbelanja?\n     1. Barang lain\t2. Promo\t3. Tidak\n");
						printf("    Pilihan anda: ");
						scanf("%d", &pilih);
							if (pilih == 1) {
								goto list;
							} else if (pilih == 2) {
								goto promo;
							} else if (pilih == 3) {
								return 0;
							}
					}
				printf("    Ingin berbelanja lagi?\n     1. Barang yang lain\t2. Promo lagi\t3. Tidak\n");
				printf("    Pilihan anda: ");
				scanf("%d", &pilih);
					if (pilih == 1 ) {
						goto list;
					} else if (pilih == 2) {
						goto promo;
					} else if (pilih == 3) {
						goto hitung;
					}
		} else {
			printf("  Maaf, barang tidak ada atau belum ready!\n");
			printf("  Ingin berbelanja?\n   1. Ya\t2. Tidak\n");
			printf("  Pilihan: ");
			scanf("%d", &pilih);
				if (pilih == 1) {
					goto list;
				}  else if (pilih == 2) {
					return 0;
				}
		}
	

	hitung:
		
		twajan = perhitungan(&jumlah.Wajan, &harga[0]);
		tsaring = perhitungan(&jumlah.Saring, &harga[1]);
		tpanci = perhitungan(&jumlah.Panci, &harga[2]);
		tsun = perhitungan(&jumlah.Sun, &harga[3]);
		tminyak = perhitungan(&jumlah.Minyak, &harga[4]);
		trinso = perhitungan(&jumlah.Rinso, &harga[5]);
		tsendok = perhitungan(&jumlah.Sendok, &harga[6]);
		tgarpu = perhitungan(&jumlah.Garpu, &harga[7]);
		
		printf("\n  Anda telah berbelanja:\n");
		if (jumlah.Wajan > 0) {
			printf("  Wajan\t\t\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Wajan, harga[0], twajan);
		} 
		if (jumlah.Saring > 0) {
			printf("  Saringan\t\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Saring, harga[1], tsaring);
		}
		if (jumlah.Panci > 0) {
			printf("  Panci\t\t\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Panci, harga[2], tpanci);
		}
		if (jumlah.Sun > 0) {
			printf("  Sunlight Lemon 800 ml\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Sun, harga[3], tsun);
		}
		if (jumlah.Minyak > 0) {
			printf("  Minyak Kelapa Sawit 1L\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Minyak, harga[4], tminyak);
		}
		if (jumlah.Rinso > 0) {
			printf("  Rinso Detergen Cair Anti Noda 750 ml\t\t%d x Rp %d\t= Rp %d\n", jumlah.Rinso, harga[5], trinso);
		}
		if (jumlah.Sendok > 0){
			printf("  Sendok\t\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Sendok, harga[6], tsendok);
		}
		if (jumlah.Garpu > 0) {
			printf("  Garpu\t\t\t\t\t\t%d x Rp %d\t= Rp %d\n", jumlah.Garpu, harga[7], tgarpu);
		}
		if (jumlah.Promo1 == 1) {
			printf("  Promo 2 Wajan\t\t\t\t\t\t\t= Rp %d\n", harga[8]);
		}
		if (jumlah.Promo2 == 1) {
			printf("  Promo 3 Panci\t\t\t\t\t\t\t= Rp %d\n", harga[9]);
		}
		if (jumlah.Promo3 == 1) {
			printf("  Promo 2 Minyak Sawit Gratis 1 Sunlight\t\t\t= Rp %d\n", harga[10]);
		}
		if (jumlah.Promo4 == 1) {
			printf("  Promo 4 Panci Gratis 1 Wajan\t\t\t\t\t= Rp %d\n", harga[11]);
		}
		printf("  Ingin menambah?\n   1. Ya\t2. Tidak\n");
		printf("  Pilihan anda: ");
		scanf("%d", &pilih);
			if (pilih == 1) {
				goto list;
			} else if (pilih == 2) {
				goto pembayaran;
			}
		
	pembayaran:
		printf("\n  Pilih metode pembayaran:\n   1. Tunai\t2. Kartu Member\n");
		printf("  Pilihan anda: ");
		scanf("%d", &metode);
			if (metode == 1) {
				printf("   Total yang harus dibayar\t\t\t\t\t= Rp %d\n", total1(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4));
				bayar1:
					printf("   Uang yang dibayar\t\t\t\t\t\t= Rp ");
					scanf("%d", &uang);
						if (uang < total1(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)) {
							printf("  Maaf, uang anda kurang\n");
							goto bayar1;
						}
					printf("   Kembalian\t\t\t\t\t\t\t= Rp %d\n", (uang - total1(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)));
				
					printf("\n\n  Ingin mencetak nota?\n   1. Ya\t2. Tidak\n");
					printf("  Pilihan anda: ");
					scanf("%d", &nota);
						if (nota == 1) {
							printf("    _______________________");
							printf("\n   |\t\t\t\t\t\t\t\t       |\n   |\t\t\t\tWas-Was Shop \t\t\t       |\n   |\t\t    Jl. Kebangsaan Indonesia Raya No. 98\t       |\n   |\t\t  Telp 021-XXXXX Kota Baru Jadi, Indonesia\t       |\n");
							printf("   |  %s  |\n   |  %s\t\t\t\t       %s   %s\t%s  |\n   |  %s  |\n", "---------------------------------------------------------------", "Nama", "qty", "Harga", "Total", "---------------------------------------------------------------");
								if (jumlah.Wajan > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Wajan", jumlah.Wajan, harga[0], twajan);
								} 
								if (jumlah.Saring > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Saringan", jumlah.Saring, harga[1], tsaring);
								}
								if (jumlah.Panci > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Panci", jumlah.Panci, harga[2], tpanci);
								}
								if (jumlah.Sun > 0) {
									printf("   |  %s\t\t\t%d    %d\t%d  |\n", "Sunlight Lemon 800 ml", jumlah.Sun, harga[3], tsun);
								}
								if (jumlah.Minyak > 0) {
									printf("   |  %s\t\t\t%d    %d\t%d  |\n", "Minyak Kelapa Sawit 1L", jumlah.Minyak, harga[4], tminyak);
								}
								if (jumlah.Rinso > 0) {
									printf("   |  %s\t%d    %d\t%d  |\n", "Rinso Detergen Cair Anti Noda 750 ml", jumlah.Rinso, harga[5], trinso);
								}
								if (jumlah.Sendok > 0){
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Sendok", jumlah.Sendok, harga[6], tsendok);
								}
								if (jumlah.Garpu > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Garpu", jumlah.Garpu, harga[7], tgarpu);
								}
								if (jumlah.Promo1 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 2 Wajan", "1", harga[8], harga[8]);
								}
								if (jumlah.Promo2 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 3 Panci", "1", harga[9], harga[9]);
								}
								if (jumlah.Promo3 == 1) {
									printf("   |  %s\t\t%s    %d\t%d  |\n", "Promo 2 Minyak Kelapa Sawit", "1", harga[10], harga[10]);
								}
								if (jumlah.Promo4 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 4 Panci", "1", harga[11], harga[11]);
								}
								printf("   |  ---------------------------------------------------------------  |\n");
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Total", total1(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4));
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Tunai", uang);
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Kembali", (uang - total1(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)));
								printf("   |  ---------------------------------------------------------------  |\n");
								printf("   |  Operator: Anda\t\t\t\t\t\t       |\n   |  Terima kasih atas kunjungannya dan periksa barang sebelum keluar |\n   |  Barang yang telah dibeli tidak dapat ditukar atau dikembalikan   |\n");
								printf("   |_______________________|\n");
						} else if (nota == 2) {
							printf("  Terima kasih kunjungannya.");
						}
			} else if (metode == 2) {
				printf("   Total yang harus dibayar\t\t\t\t\t= Rp %d\n", total2(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4));
				bayar2:
				printf("   Uang yang dibayar\t\t\t\t\t\t= Rp ");
				scanf("%d", &uang);
				if (uang < total2(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)) {
							printf("  Maaf, jumlah uang yang anda input melalui kartu kurang dari total biaya\n");
							goto bayar2;
						}
				printf("   Kembalian\t\t\t\t\t\t\t= Rp %d\n", (uang - total2(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)));
				
				printf("\n\n  Ingin mencetak nota?\n   1. Ya\t2. Tidak\n");
					printf("  Pilihan anda: ");
					scanf("%d", &nota);
						if (nota == 1) {
							printf("    _______________________");
							printf("\n   |\t\t\t\t\t\t\t\t       |\n   |\t\t\t\tWas-Was Shop \t\t\t       |\n   |\t\t    Jl. Kebangsaan Indonesia Raya No. 98\t       |\n   |\t\t  Telp 021-XXXXX Kota Baru Jadi, Indonesia\t       |\n");
							printf("   |  %s  |\n   |  %s\t\t\t\t       %s   %s\t%s  |\n   |  %s  |\n", "---------------------------------------------------------------", "Nama", "qty", "Harga", "Total", "---------------------------------------------------------------");
								if (jumlah.Wajan > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Wajan", jumlah.Wajan, harga[0], twajan);
								} 
								if (jumlah.Saring > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Saringan", jumlah.Saring, harga[1], tsaring);
								}
								if (jumlah.Panci > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Panci", jumlah.Panci, harga[2], tpanci);
								}
								if (jumlah.Sun > 0) {
									printf("   |  %s\t\t\t%d    %d\t%d  |\n", "Sunlight Lemon 800 ml", jumlah.Sun, harga[3], tsun);
								}
								if (jumlah.Minyak > 0) {
									printf("   |  %s\t\t\t%d    %d\t%d  |\n", "Minyak Kelapa Sawit 1L", jumlah.Minyak, harga[4], tminyak);
								}
								if (jumlah.Rinso > 0) {
									printf("   |  %s\t%d    %d\t%d  |\n", "Rinso Detergen Cair Anti Noda 750 ml", jumlah.Rinso, harga[5], trinso);
								}
								if (jumlah.Sendok > 0){
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Sendok", jumlah.Sendok, harga[6], tsendok);
								}
								if (jumlah.Garpu > 0) {
									printf("   |  %s\t\t\t\t\t%d    %d\t%d  |\n", "Garpu", jumlah.Garpu, harga[7], tgarpu);
								}
								if (jumlah.Promo1 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 2 Wajan", "1", harga[8], harga[8]);
								}
								if (jumlah.Promo2 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 3 Panci", "1", harga[9], harga[9]);
								}
								if (jumlah.Promo3 == 1) {
									printf("   |  %s\t\t%s    %d\t%d  |\n", "Promo 2 Minyak Kelapa Sawit", "1", harga[10], harga[10]);
								}
								if (jumlah.Promo4 == 1) {
									printf("   |  %s\t\t\t\t%s    %d\t%d  |\n", "Promo 4 Panci", "1", harga[11], harga[11]);
								}
								printf("   |  ---------------------------------------------------------------  |\n");
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Total", total2(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4));
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Tunai", uang);
								printf("   |  %s\t\t\t\t\t\t: Rp %-10d|\n", "Kembali", (uang - total2(&twajan, &tsaring, &tpanci, &tsun, &tminyak, &trinso, &tsendok, &tgarpu, &tpromo1, &tpromo2, &tpromo3, &tpromo4)));
								printf("   |  ---------------------------------------------------------------  |\n");
								printf("   |  Operator: Anda\t\t\t\t\t\t       |\n   |  Terima kasih atas kunjungannya dan periksa barang sebelum keluar |\n   |  Barang yang telah dibeli tidak dapat ditukar atau dikembalikan   |\n");
								printf("   |_______________________|\n");
						} else if (nota == 2) {
							printf("  Terima kasih kunjungannya.");
						}
			}
		
	return 0;
}