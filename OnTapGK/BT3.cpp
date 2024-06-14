#include"fraction.h"

int main() {
	int tu1, tu2, mau1, mau2;
	cin >> tu1 >> mau1 >> tu2 >> mau2;
	phanSo ps1(tu1, mau1);
	phanSo ps2(tu2, mau2);
	phanSo ps;
	ps.findSum(ps1, ps2);
	ps.findAbstract(ps1, ps2);
	ps.findProduct(ps1, ps2);
	ps.findQuotient(ps1, ps2);
	ps1.findShorten(ps1);
	ps2.findShorten(ps2);
	ps1.isSimplified(ps1);
	ps2.isSimplified(ps2);
	ps.compare(ps1, ps2);

	return 0;
}