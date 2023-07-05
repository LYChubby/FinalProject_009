#include <iostream>
using namespace std;

class MataKuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;
public:
	MataKuliah() {
		presensi = 0;
		activity = 0;
		exercise = 0;
		tugasAkhir = 0;
	}
	virtual float hitungNilaiAkhir() { return 0; }
	virtual void cekKelulusan() { return; }
	virtual void input() {}

	void setP(float nilai) {
		this->presensi = nilai;
	}

	float getP() {
		return presensi;
	}
	
	void setA(float nilai) {
		this->activity = nilai;
	}

	float getA() {
		return activity;
	}

	void setE(float nilai) {
		this->exercise = nilai;
	}

	float getE() {
		return exercise;
	}

	void setUA(float nilai) {
		this->tugasAkhir = nilai;
	}

	float getUA() {
		return tugasAkhir;
	}
};

class Pemrograman : public MataKuliah {
public:
	Pemrograman() {
		cout << "Program Dibuat\n";
	}

	void input() {
		float p;
		float a;
		float e;
		float ua;

		cout << "Masukkan Nilai Presensi : ";
		cin >> p;
		setP(p);

		cout << "Masukkan Nilai Activity : ";
		cin >> a;
		setA(a);

		cout << "Masukkan Nilai Exercise : ";
		cin >> e;
		setE(e);

		cout << "Masukkan Nilai Tugas Akhir : ";
		cin >> ua;
		setUA(ua);
	}

		float hitungNilaiAkhir() {
			float NilAkhir = ((getP() * 0.1) + (getA() * 0.2) + (getE() * 0.3) + (getUA() * 0.4));
			return NilAkhir;
		}

		void cekKelulusan() {
			float NilAkhir = hitungNilaiAkhir();

			if (NilAkhir > 75) {
				cout << "\nSelamat, Anda Lulus Mata Kuliah Pemrograman Dengan Nilai Akhir " << NilAkhir;
			}
			else {
				cout << "\nMohon Maaf, Anda Tidak Lulus Mata Kuliah Pemrograman Dengan Nilai Akhir " << NilAkhir;
			}
		}
};

int main() {
	char ulang;

	do {
		Pemrograman pm;
		pm.input();
		pm.cekKelulusan();

		cout << "\nApakah Anda Ingin Mengulang Program ? (Y / N) : ";
		cin >> ulang;
	} while (ulang == 'Y' || ulang == 'y');

	return 0;
}