#include <iostream>
#include <Windows.h>

#define NUM_OF_TOWERS 3
#define HANOI_SIZE 5

class TowerOfHanoi {
	public:
		int **towers;
		int num_of_discs;

		TowerOfHanoi(int n) {
			this->num_of_discs = n;
			this->towers = new int *[NUM_OF_TOWERS];
			for (int i = 0; i < NUM_OF_TOWERS; i++) {
				this->towers[i] = new int[n];
				std::memset(this->towers[i], 0, n * sizeof(int));
			}
			for (int i = 0; i < n; i++) {
				this->towers[0][i] = i + 1;
			}
		}

		void moveDisc(int source, int target) {
			int source_h = 0;
			while (towers[source][source_h] == 0) {
				source_h++;
			}
			int target_h = num_of_discs;
			while (towers[target][target_h] != 0 ) {
				target_h--;
			}
			if (target_h != num_of_discs - 1) {
				if (towers[source][source_h] > towers[target][target_h + 1])
					return;
			}
			std::swap(towers[source][source_h], towers[target][target_h]);
		}

		void solve(int n, int source, int target, int auxiliary) {
			if (n > 0) {
				solve(n - 1, source, auxiliary, target);
				moveDisc(source, target);
				print();
				Sleep(300);
				system("cls");
				solve(n - 1, auxiliary, target, source);
			}
		}

		void print() {
			for (int i = 0; i < num_of_discs; i++) {
				for (int j = 0; j < NUM_OF_TOWERS; j++) {
					int disc_w = 2 * towers[j][i];
					int tower_w = 2 * num_of_discs;
					int pole = tower_w / 2;
					int w = 0;
					while (w <= tower_w) {
						if (w > pole - disc_w / 2 && w < pole + disc_w / 2)
							std::cout << "=";
						else
							std::cout << " ";
						w++;
					}
				}
				std::cout << std::endl;
			}
		}

};

int main() {
	TowerOfHanoi toh = TowerOfHanoi(HANOI_SIZE);
	system("cls");
	toh.print();
	Sleep(300);
	system("cls");
	toh.solve(HANOI_SIZE, 0, 2, 1);
	return 0;
}