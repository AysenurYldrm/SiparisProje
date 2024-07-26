#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

int main()
{

	int secim;
	char islem;
	char cevap = 'e';

	//urun.txt 
	int urunKodu;
	string urunAdi;
	string ureticisi;
	float teminSuresi;
	string uretimTarihi;
	float fiyatGenel;
	float fiyatOzel;
	float kdvOrani;
	int stokAdedi;

	//cari.txt 
	int firmaNo;
	string firmaAdi;
	int firmaTelefon;
	string firmaSorumlusu;
	string musteriKategorisi; //genel / ozel
	string musteriadres;

	//siparis.txt
	int siparisFirmaNo;//değişcek
	string siparisTarihi;
	float siparisTutari;
	fstream siparisListesiDosyasi;
	string siparisiAlan;

	//siparisListesiDosyasi.txt
	int urunKodu1;
	int urunAdedi;

	do
	{
		cout << "\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << " =- SIPARIS SATIS ISLEMLERI PROGRAMI -=" << endl;
		cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

		cout << "\n 1) Urun islemleri" << endl;
		cout << "\n 2) Musteri dosyasi islemleri" << endl;
		cout << "\n 3) Siparis islemleri" << endl;
		cout << "\n 4) Cikis" << endl;
		cout << "\n Seciminiz: "; cin >> secim;

		if (secim < 1 || secim > 4)
		{
			cout << "\n Lutfen istenilen seceneklerden birini giriniz! " << endl;
		}

		switch (secim)
		{
		case 1:
			system("cls");
			int urunIslem;

			do {
				cout << "\n ---------- URUN ISLEMLERI ----------" << endl;
				cout << "\n 1) Urun ekleme" << endl;
				cout << "\n 2) Urun silme" << endl;
				cout << "\n 3) Urun arama" << endl;
				cout << "\n 4) Duzenleme" << endl;
				cout << "\n 5) Listeleme" << endl;
				cout << "\n Seciminiz: "; cin >> urunIslem;

				if (urunIslem < 1 || urunIslem > 5)
				{
					cout << "\n Lutfen istenilen seceneklerden birini giriniz!  " << endl;
				}

			} while (urunIslem != 1 && urunIslem != 2 && urunIslem != 3 && urunIslem != 4 && urunIslem != 5);

			//Urun Ekleme
			if (urunIslem == 1)
			{
				system("cls");
				cout << "\n * URUN EKLEME *" << endl;
				bool control = true;

				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("urun.txt", ios::app);

				do {

					cout << "\n===== Eklenen Urun Bilgileri =====" << endl;
					cout << "\n Urun Kodu:	"; cin >> urunKodu1;

					while (!DosyaOku.eof())
					{
						DosyaOku >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;
						do
						{
							if (urunKodu == urunKodu1)
							{
								cout << endl << urunKodu << " kodlu urun zaten bulunuyor." << endl;
								cout << "\n Yeni urun Kodu:	"; cin >> urunKodu1;
							}
							else
							{
								control = false;
							}
						} while (control);
					}

					cout << "\n Urun Adi:	"; cin >> urunAdi;
					cout << "\n Urunun Ureticisi:	"; cin >> ureticisi;
					cout << "\n Urunun Temin Suresi:	"; cin >> teminSuresi;
					cout << "\n Uretim Tarihi:	"; cin >> uretimTarihi;
					cout << "\n Fiyat genel:	"; cin >> fiyatGenel;
					cout << "\n Fiyat ozel:	 "; cin >> fiyatOzel;
					cout << "\n KDV orani:	"; cin >> kdvOrani;
					cout << "\n Stok Adedi:	"; cin >> stokAdedi;
					cout << "\n==================================" << endl;

					DosyaYaz << "\n" << urunKodu1 << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
					cout << "\n Baska urun kayidi yapacak misin? (e/E) (h/H) "; cin >> cevap;

				} while (!(cevap == 'h' || cevap == 'H'));

				cout << "\n Urun Kayit Isleminiz Gerceklesmistir..." << endl;
				DosyaYaz.close();
				DosyaOku.close();
			}

			//Urun Silme
			else if (urunIslem == 2)
			{
				system("cls");
				int silinecekUrunNo;
				int gecici = 0;

				cout << "\n * URUN SILME *" << endl;
				cout << "\n Silinecek urunun kodunu giriniz :"; cin >> silinecekUrunNo;

				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz("gecici_1.tmp");

				while (!DosyaOku.eof())
				{
					DosyaOku >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

					if (urunKodu == silinecekUrunNo)
					{
						cout << "\n===== Silinen Urun Bilgileri =====" << endl;
						cout << "\n Urun Kodu:	" << urunKodu << endl;
						cout << "\n Urun Adi:	" << urunAdi << endl;
						cout << "\n Urunun Ureticisi:	" << ureticisi << endl;
						cout << "\n Urunun Temin Suresi:	" << teminSuresi << endl;
						cout << "\n Uretim Tarihi:" << uretimTarihi << endl;
						cout << "\n Fiyat genel:	" << fiyatGenel << endl;
						cout << "\n Fiyat ozel:	 " << fiyatOzel << endl;
						cout << "\n KDV orani:	" << kdvOrani << endl;
						cout << "\n Stok Adedi:	" << stokAdedi << endl;
						cout << "\n==================================" << endl;
						cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;

						gecici = 1;
					}
					else
					{
						DosyaYaz << "\n" << urunKodu << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Silinecek Urun Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
				}

				DosyaOku.close();
				DosyaYaz.close();

				remove("urun.txt");
				rename("gecici_1.tmp", "urun.txt");
			}

			//Urun Arama
			else if (urunIslem == 3)
			{
				system("cls");
				int aranacakUrunNo;
				int gecici = 0;

				cout << "\n * URUN ARAMA *" << endl;
				cout << "\n Aranacak urunun numarasini giriniz(1-15 arasinda) :"; cin >> aranacakUrunNo;

				ifstream DosyaOku("urun.txt");

				while (!(DosyaOku.eof()))
				{
					DosyaOku >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

					if (urunKodu == aranacakUrunNo)
					{
						cout << "\n===== Aranan Urun Bilgileri =====" << endl;
						cout << "\n Urun Kodu:	" << urunKodu;
						cout << "\n Urun Adi:	" << urunAdi;
						cout << "\n Urunun Ureticisi:	" << ureticisi;
						cout << "\n Urunun Temin Suresi:	" << teminSuresi;
						cout << "\n Uretim Tarihi:	" << uretimTarihi;
						cout << "\n Fiyat genel:	" << fiyatGenel;
						cout << "\n Fiyat ozel:	 " << fiyatOzel;
						cout << "\n KDV orani:	" << kdvOrani;
						cout << "\n Stok Adedi:	" << stokAdedi;
						cout << "\n=================================" << endl;

						cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
						DosyaOku.close();
						gecici = 1;
						break;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Urun Kayidi Bulunmamaktadir..." << endl;
				}

				DosyaOku.close();
			}

			//Urun Duzeltme
			else if (urunIslem == 4)
			{
				system("cls");
				int duzenlenecekUrun;
				int gecici = 0;

				cout << "\n * URUN DUZELTME *" << endl;

				cout << "\n Duzenlenecek urunun kodunu giriniz:";  cin >> duzenlenecekUrun;

				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz("gecici_3.tmp");

				while (!DosyaOku.eof())
				{
					DosyaOku >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

					if (urunKodu == duzenlenecekUrun)
					{
						cout << "\n===== Duzenlenecek Urun Bilgileri =====" << endl;
						cout << "\n Urun Kodu:	"; cin >> urunKodu;
						cout << "\n Urun Adi:	"; cin >> urunAdi;
						cout << "\n Urunun Ureticisi:	"; cin >> ureticisi;
						cout << "\n Urunun Temin Suresi:	"; cin >> teminSuresi;
						cout << "\n Uretim Tarihi:	"; cin >> uretimTarihi;
						cout << "\n Fiyat genel:	"; cin >> fiyatGenel;
						cout << "\n Fiyat ozel:	 "; cin >> fiyatOzel;
						cout << "\n KDV orani:	"; cin >> kdvOrani;
						cout << "\n Stok Adedi:	"; cin >> stokAdedi;
						cout << "\n=====================================" << endl;

						gecici = 1;
					}

					DosyaYaz << "\n" << urunKodu << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
				}

				if (gecici == 0)
				{
					cout << "\n Duzenlenecek Urun Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Duzenleme Isleminiz Gerceklesmistir..." << endl;
				}

				DosyaOku.close();
				DosyaYaz.close();

				remove("urun.txt");
				rename("gecici_3.tmp", "urun.txt");
			}

			//Urun Listeleme
			else if (urunIslem == 5)
			{
				system("cls");

				cout << "\n * LISTELEME *" << endl;

				ifstream DosyaOku("urun.Txt");


				while (!DosyaOku.eof())
				{
					DosyaOku >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

					cout << "\n===== Listelenecek Urun Bilgileri =====" << endl;
					cout << "\n Urun Kodu:" << urunKodu << endl;
					cout << "\n Urun Adi:" << urunAdi << endl;
					cout << "\n Urunun Ureticisi:" << ureticisi << endl;
					cout << "\n Urunun Temin Suresi:" << teminSuresi << endl;
					cout << "\n Uretim Tarihi:" << uretimTarihi << endl;
					cout << "\n Fiyat genel:" << fiyatGenel << endl;
					cout << "\n Fiyat ozel:" << fiyatOzel << endl;
					cout << "\n KDV orani:" << kdvOrani << endl;
					cout << "\n Stok Adedi:" << stokAdedi << endl;
					cout << "\n=====================================" << endl;
				}

				DosyaOku.close();
			}

			break;

		case 2:
			system("cls");
			int musteriDosyaIslem;

			do {
				cout << "\n ---------- MUSTERI DOSYA ISLEMLERI ----------" << endl;
				cout << "\n 1) Musteri dosyasi ekleme" << endl;
				cout << "\n 2) Musteri dosyasi  silme" << endl;
				cout << "\n 3) Musteri dosyasi  arama" << endl;
				cout << "\n 4) Musteri dosyasi duzeltme" << endl;
				cout << "\n Seciminiz: "; cin >> musteriDosyaIslem;

				if (musteriDosyaIslem < 1 || musteriDosyaIslem > 4)
				{
					cout << "\n !!! Lutfen 4 secenekten birini seciniz !!!" << endl;
				}

			} while (musteriDosyaIslem != 1 && musteriDosyaIslem != 2 && musteriDosyaIslem != 3 && musteriDosyaIslem != 4);

			//Musteri Ekleme
			if (musteriDosyaIslem == 1)
			{
				system("cls");
				cout << "\n * MUSTERI DOSYA EKLEME *" << endl;

				int firmaNo1;
				bool control = true;

				ifstream DosyaOku("cari.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("cari.txt", ios::app);

				do {
					cout << "\n===== Eklenen Musteri Bilgileri =====" << endl;
					cout << "\n Firma No              :"; cin >> firmaNo1;

					while (!DosyaOku.eof())
					{
						DosyaOku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

						do
						{
							if (firmaNo == firmaNo1)
							{
								cout << endl << firmaNo << " nolu firma zaten bulunuyor." << endl;
								cout << "\n Yeni firma Kodu:	"; cin >> firmaNo1;
							}
							else
							{
								control = false;
							}
						} while (control);
					}

					cout << "\n Firma Adi          :"; cin >> firmaAdi;
					cout << "\n Firma telefon  :"; cin >> firmaTelefon;
					cout << "\n Firma Sorumlusu    :"; cin >> firmaSorumlusu;
					cout << "\n Musteri kategorisi (genel/ozel) :"; cin >> musteriKategorisi;
					cout << "\n Adres :"; cin >> musteriadres;
					cout << "\n===================================" << endl;

					DosyaYaz << "\n" << firmaNo1 << ' ' << firmaAdi << ' ' << firmaTelefon << ' ' << firmaSorumlusu << ' ' << musteriKategorisi << ' ' << musteriadres;
					cout << "\n Baska musteri kayidi yapacak misin? (e/E) (h/H) "; cin >> cevap;

				} while (!(cevap == 'h' || cevap == 'H'));

				cout << "\n Musteri Dosyasi Ekleme Isleminiz Gerceklesmistir..." << endl;
				DosyaYaz.close();
				DosyaOku.close();
			}

			//Musteri Silme
			else if (musteriDosyaIslem == 2)
			{
				system("cls");
				int silinecekMusteriNo;
				int gecici = 0;

				cout << "\n * MUSTERI BILGILERI SILME *" << endl;
				cout << "\n Silinecek musterinin kodunu giriniz :"; cin >> silinecekMusteriNo;

				ifstream DosyaOku("cari.txt");
				ofstream DosyaYaz("gecici_x.tmp");

				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

					if (silinecekMusteriNo == firmaNo)
					{
						cout << "\n===== Silinen Musteri Bilgileri =====" << endl;
						cout << "\n Firma Kodu:	" << firmaNo << endl;
						cout << "\n Firma Adi:	" << firmaAdi << endl;
						cout << "\n Firma Telefon: " << firmaTelefon << endl;
						cout << "\n Firma Sorumlusu: " << firmaSorumlusu << endl;
						cout << "\n Musteri kategorisi : " << musteriKategorisi << endl;
						cout << "\n Musteri adres:	" << musteriadres << endl;
						cout << "\n==================================" << endl;
						cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
						gecici = 1;
					}
					else
					{
						DosyaYaz << "\n" << firmaNo << ' ' << firmaAdi << ' ' << firmaTelefon << ' ' << firmaSorumlusu << ' ' << musteriKategorisi << ' ' << musteriadres;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Silinecek Musteri Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
				}

				DosyaOku.close();
				DosyaYaz.close();

				remove("cari.txt");
				rename("gecici_x.tmp", "cari.txt");
			}

			//Musteri Arama
			else if (musteriDosyaIslem == 3)
			{
				system("cls");
				int aranacakMusteriNo;
				int gecici = 0;

				cout << "\n * MUSTERI DOSYA ARAMA *" << endl;
				cout << "\n Aranacak musterinin numarasini giriniz :"; cin >> aranacakMusteriNo;

				ifstream DosyaOku("cari.txt");

				while (!(DosyaOku.eof()))
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

					if (firmaNo == aranacakMusteriNo)
					{
						cout << "\n===== Aranan Musteri Bilgileri =====" << endl;
						cout << "\n Firma No :" << firmaNo << endl;
						cout << "\n Firma Adi :" << firmaAdi << endl;
						cout << "\n Firma telefon :" << firmaTelefon << endl;
						cout << "\n Firma Sorumlusu :" << firmaSorumlusu << endl;
						cout << "\n Musteri kategorisi :" << musteriKategorisi << endl;
						cout << "\n Adres :" << musteriadres << endl;
						cout << "\n==================================" << endl;

						cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
						DosyaOku.close();
						gecici = 1;
						break;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Musteri Dosya Kaydi Bulunmamaktadir..." << endl;
				}

				DosyaOku.close();
			}

			//Musteri Duzeltme
			else if (musteriDosyaIslem == 4)
			{
				system("cls");
				int duzenlenecekMusteriDosya;
				int gecici = 0;

				cout << "\n * MUSTERI DOSYA DUZELTME *" << endl;

				cout << "\n Duzenlenecek musteri dosyasi icin firma kodunu giriniz:";  cin >> duzenlenecekMusteriDosya;

				ifstream DosyaOku("cari.txt");
				ofstream DosyaYaz("gecici_y.tmp");

				while (!DosyaOku.eof())
				{
					DosyaOku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

					if (firmaNo == duzenlenecekMusteriDosya)
					{
						cout << "\n===== Duzenlenecek Musteri Dosyasi Bilgileri =====" << endl;
						cout << "\n Firma No  :"; cin >> firmaNo;
						cout << "\n Firma Adi  :"; cin >> firmaAdi;
						cout << "\n Firma telefon  :"; cin >> firmaTelefon;
						cout << "\n Firma Sorumlusu  :"; cin >> firmaSorumlusu;
						cout << "\n Musteri kategorisi(genel/ozel): "; cin >> musteriKategorisi;
						cout << "\n Adres :"; cin >> musteriadres;
						cout << "\n=====================================" << endl;

						gecici = 1;
					}

					DosyaYaz << "\n" << firmaNo << ' ' << firmaAdi << ' ' << firmaTelefon << ' ' << firmaSorumlusu << ' ' << musteriKategorisi << ' ' << musteriadres;
				}

				if (gecici == 0)
				{
					cout << "\n Duzenlenecek Musteri Dosya Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Duzenleme Isleminiz Gerceklesmistir..." << endl;
				}

				DosyaOku.close();
				DosyaYaz.close();

				remove("cari.txt");
				rename("gecici_y.tmp", "cari.txt");
			}

			break;

		case 3:
			system("cls");
			int siparisIslem;

			do {
				cout << "\n ---------- SIPARIS ISLEMLERI ----------" << endl;
				cout << "\n 1) Siparis olustur" << endl;
				cout << "\n 2) Siparis arama" << endl;
				cout << "\n 3) Siparis silme" << endl;
				cout << "\n 4) Siparis duzeltme" << endl;
				cout << "\n 5) Siparis raporlama" << endl;
				cout << "\n Seciminiz: "; cin >> siparisIslem;

				if (siparisIslem < 1 || siparisIslem > 5)
				{
					cout << "\n Lutfen istenilen seceneklerden birini seciniz!" << endl;
				}

			} while (siparisIslem != 1 && siparisIslem != 2 && siparisIslem != 3 && siparisIslem != 4 && siparisIslem != 5);

			//Siparis Olusturma
			if (siparisIslem == 1)
			{
				system("cls");

				cout << "\n * SIPARIS OLUSTURMA *" << endl;

				ifstream DosyaOkuUrun("urun.txt");
				ifstream DosyaOkuCari("cari.txt");


				ofstream DosyaYaz;
				ofstream DosyaYazUrun;
				ofstream siparisListesiDosyasi;

				DosyaYaz.open("siparis.txt", ios::app);
				DosyaYazUrun.open("temp.txt", ios::app);
				siparisListesiDosyasi.open("siparisList.txt", ios::app);

				do {

					cout << "\n===== Olusturulan Siparis Bilgileri =====" << endl << endl;

					while (!(DosyaOkuCari.eof()))
					{
						DosyaOkuCari >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

						cout << firmaNo << " ,";
					}
					cout << " nolu firmalardan siparis olusturabilirsiniz." << endl;
					cout << "\n Siparisi alan firma no: "; cin >> siparisFirmaNo;
					cout << "\n Siparis tarihi:	"; cin >> siparisTarihi;
					cout << "\n Siparisi alan:	"; cin >> siparisiAlan;
					cout << "\n Siparis Listesindeki urun kodu:	"; cin >> urunKodu1;
					cout << "\n Siparis Listesindeki urun adedi:	"; cin >> urunAdedi;
					cout << "\n==================================" << endl;

					while (!DosyaOkuUrun.eof())
					{
						DosyaOkuUrun >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

						if (urunKodu == urunKodu1)
						{
							while (!DosyaOkuCari.eof())
							{
								DosyaOkuCari >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

								if (firmaNo == siparisFirmaNo)
								{
									if (musteriKategorisi == "genel")
									{
										siparisTutari = (fiyatGenel * (1 + kdvOrani)) * urunAdedi;
									}
									else if (musteriKategorisi == "ozel")
									{
										siparisTutari = (fiyatOzel * (1 + kdvOrani)) * urunAdedi;
									}
								}
							}
							stokAdedi = stokAdedi - urunAdedi;
						}

						DosyaYazUrun << "\n" << urunKodu << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
					}

					DosyaYaz << "\n" << siparisFirmaNo << ' ' << siparisTarihi << ' ' << siparisTutari << ' ' << siparisiAlan << ' ' << urunKodu1 << ' ' << urunAdedi;
					siparisListesiDosyasi << "\n" << urunKodu1 << ' ' << urunAdedi;

					cout << "\n Baska siparis olusturacak misin? (e/E) (h/H) "; cin >> cevap;

				} while (!(cevap == 'h' || cevap == 'H'));

				cout << "\n Siparisiniz Basariyla Olusturulmustur...Sepetinizdeki urun tutari = " << siparisTutari << " TL" << endl;

				DosyaOkuCari.close();
				DosyaOkuUrun.close();
				DosyaYazUrun.close();
				DosyaYaz.close();
				siparisListesiDosyasi.close();
				remove("urun.txt");
				rename("temp.txt", "urun.txt");

			}

			//Siparis Arama
			else if (siparisIslem == 2)
			{
				system("cls");
				int arananSiparis;
				int gecici = 0;

				cout << "\n * SIPARIS ARAMA *" << endl;
				cout << "\n Aranacak siparisin numarasini giriniz :"; cin >> arananSiparis;

				ifstream DosyaOku("siparis.txt");

				while (!(DosyaOku.eof()))
				{
					DosyaOku >> siparisFirmaNo >> siparisTarihi >> siparisTutari >> siparisiAlan >> urunKodu1 >> urunAdedi;


					if (siparisFirmaNo == arananSiparis)
					{
						cout << "\n===== Aranan Siparis Bilgileri =====" << endl;
						cout << "\n Siparis numarasi :" << siparisFirmaNo << endl;
						cout << "\n Siparis tarihi :" << siparisTarihi << endl;
						cout << "\n Siparis tutari :" << siparisTutari << endl;
						cout << "\n Siparisi alan :" << siparisiAlan << endl;
						cout << "\n Siparis Listesindeki urun kodu:" << urunKodu1 << endl;
						cout << "\n Siparis Listesindeki urun adedi:" << urunAdedi << endl;
						cout << "\n==================================" << endl;

						cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
						DosyaOku.close();
						gecici = 1;
						break;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Siparis Kaydi Bulunmamaktadir..." << endl;
				}

				DosyaOku.close();
			}

			//Siparis Silme
			else if (siparisIslem == 3)
			{
				system("cls");
				int silinecekSiparisNo;
				int gecici = 0;

				cout << "\n * SIPARIS SILME *" << endl;
				cout << "\n Silinecek siparisin kodunu giriniz :"; cin >> silinecekSiparisNo;

				ifstream DosyaOku("siparis.txt");
				ifstream DosyaOkuUrun("urun.txt");

				ofstream DosyaYaz("gecici_2.tmp");
				ofstream DosyaYazList("gecici_3.tmp");
				ofstream DosyaYazUrun("temp.txt");

				while (!DosyaOku.eof())
				{
					DosyaOku >> siparisFirmaNo >> siparisTarihi >> siparisTutari >> siparisiAlan >> urunKodu1 >> urunAdedi;

					if (siparisFirmaNo == silinecekSiparisNo)
					{
						cout << "\n===== Silinen Siparis Bilgileri =====" << endl;
						cout << "\n Siparis numarasi :" << siparisFirmaNo << endl;
						cout << "\n Siparis tarihi :" << siparisTarihi << endl;
						cout << "\n Siparis tutari :" << siparisTutari << endl;
						cout << "\n Siparisi alan :" << siparisiAlan << endl;
						cout << "\n Siparis Listesindeki urun kodu:" << urunKodu1 << endl;
						cout << "\n Siparis Listesindeki urun adedi:" << urunAdedi << endl;
						cout << "\n==================================" << endl;
						cout << "\n Siparisiniz Basariyla Silinmistir..." << endl;

						gecici = 1;

						while (!DosyaOkuUrun.eof())
						{
							DosyaOkuUrun >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

							if (urunKodu == urunKodu1)
							{
								stokAdedi = stokAdedi + urunAdedi;
							}
							DosyaYazUrun << "\n" << urunKodu << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
						}
					}
					else
					{
						DosyaYaz << "\n" << siparisFirmaNo << ' ' << siparisTarihi << ' ' << siparisTutari << ' ' << siparisiAlan << ' ' << urunKodu1 << ' ' << urunAdedi;
						DosyaYazList << "\n" << urunKodu1 << ' ' << urunAdedi;
					}
				}

				if (gecici == 0)
				{
					cout << "\n Silinecek Siparis Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
				}

				DosyaOkuUrun.close();
				DosyaYazUrun.close();
				DosyaOku.close();
				DosyaYaz.close();
				DosyaYazList.close();

				remove("siparis.txt");
				remove("siparisList.txt");
				remove("urun.txt");

				rename("temp.txt", "urun.txt");
				rename("gecici_2.tmp", "siparis.txt");
				rename("gecici_3.tmp", "siparisList.txt");
			}

			//Siparis Duzeltme
			else if (siparisIslem == 4)
			{
				system("cls");
				int duzenlenecekSiparis;
				int gecici = 0;

				cout << "\n * SIPARIS DUZELTME *" << endl;

				cout << "\n Duzenlenecek siparisin kodunu giriniz:";  cin >> duzenlenecekSiparis;

				ifstream DosyaOkuUrun("urun.txt");
				ifstream DosyaOkuCari("cari.txt");
				ifstream DosyaOku("siparis.txt");

				ofstream DosyaYaz("gecici1.tmp");
				ofstream DosyaYazList("gecici2.tmp");
				ofstream DosyaYazUrun("temp.txt");

				while ((!DosyaOku.eof()))
				{
					DosyaOku >> siparisFirmaNo >> siparisTarihi >> siparisTutari >> siparisiAlan >> urunKodu1 >> urunAdedi;

					if (siparisFirmaNo == duzenlenecekSiparis)
					{
						cout << "\n===== Duzenlenecek Siparis Bilgileri =====" << endl;
						cout << "\n Siparis firma no: "; cin >> siparisFirmaNo;
						cout << "\n Siparis tarihi:	"; cin >> siparisTarihi;
						cout << "\n Siparisi alan:	"; cin >> siparisiAlan;
						cout << "\n Siparis Listesindeki urun kodu:	"; cin >> urunKodu1;
						cout << "\n Siparis Listesindeki urun adedi:	"; cin >> urunAdedi;
						cout << "\n=====================================" << endl;


						while (!DosyaOkuUrun.eof())
						{
							DosyaOkuUrun >> urunKodu >> urunAdi >> ureticisi >> teminSuresi >> uretimTarihi >> fiyatGenel >> fiyatOzel >> kdvOrani >> stokAdedi;

							if (urunKodu == urunKodu1)
							{
								while (!DosyaOkuCari.eof())
								{
									DosyaOkuCari >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> musteriKategorisi >> musteriadres;

									if (firmaNo == siparisFirmaNo)
									{
										if (musteriKategorisi == "genel")
										{
											siparisTutari = (fiyatGenel * (1 + kdvOrani)) * urunAdedi;
										}
										else if (musteriKategorisi == "ozel")
										{
											siparisTutari = (fiyatOzel * (1 + kdvOrani)) * urunAdedi;
										}
									}
								}

								stokAdedi = stokAdedi - urunAdedi;
							}

							DosyaYazUrun << "\n" << urunKodu << ' ' << urunAdi << ' ' << ureticisi << ' ' << teminSuresi << ' ' << uretimTarihi << ' ' << fiyatGenel << ' ' << fiyatOzel << ' ' << kdvOrani << ' ' << stokAdedi;
						}

						DosyaYaz << "\n" << siparisFirmaNo << ' ' << siparisTarihi << ' ' << siparisTutari << ' ' << siparisiAlan << ' ' << urunKodu1 << ' ' << urunAdedi;
						DosyaYazList << "\n" << urunKodu1 << ' ' << urunAdedi;


						gecici = 1;
					}

				}
				if (gecici == 0)
				{
					cout << "\n Duzenlenecek Siparis Kayidi Bulunmamaktadir..." << endl;
				}

				else if (gecici == 1)
				{
					cout << "\n Siparis Basariyla Duzenlenmistir..." << endl;
				}

				DosyaOkuCari.close();
				DosyaOkuUrun.close();
				DosyaYazUrun.close();
				DosyaOku.close();
				DosyaYaz.close();
				DosyaYazList.close();

				remove("urun.txt");
				remove("siparis.txt");
				remove("siparisList.txt");

				rename("temp.txt", "urun.txt");
				rename("gecici1.tmp", "siparis.txt");
				rename("gecici2.tmp", "siparisList.txt");
			}

			//Siparis Raporlama
			else if (siparisIslem == 5)
			{
				system("cls");
				int raporlanacakSiparis;


				cout << "\n * SIPARIS RAPORU *" << endl;

				ifstream DosyaOku("siparis.txt");

				while (!(DosyaOku.eof()))
				{
					DosyaOku >> siparisFirmaNo >> siparisTarihi >> siparisTutari >> siparisiAlan >> urunKodu1 >> urunAdedi;

					cout << "\n===== Raporlanan Siparis =====" << endl;
					cout << "\n Siparis numarasi :" << siparisFirmaNo << endl;
					cout << "\n Siparis tarihi :" << siparisTarihi << endl;
					cout << "\n Siparis tutari :" << siparisTutari << " TL" << endl;
					cout << "\n Siparisi alan :" << siparisiAlan << endl;
					cout << "\n Siparis Listesindeki urun kodu:" << urunKodu1 << endl;
					cout << "\n Siparis Listesindeki urun adedi:" << urunAdedi << endl;
					cout << "\n==================================" << endl;

				}

				DosyaOku.close();

			}

			break;

		default:
			exit(0);
		}

		cout << "\n Programi kullanmaya devam etmek istiyor musunuz? (e/E) (h/H)"; cin >> islem;
		system("cls");

	} while (islem == 'e' || islem == 'E');

	return 0;
}