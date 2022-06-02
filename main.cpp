#include <iostream>

#define NUM_OF_TOWERS 3

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

		void moveDisc(int src, int dest) {
			int src_h = 0;
			while (towers[src][src_h] == 0) {
				src_h++;
			}
			int dest_h = num_of_discs;
			while (towers[dest][dest_h] != 0 ) {
				dest_h--;
			}
			if (dest_h != num_of_discs - 1) {
				if (towers[src][src_h] > towers[dest][dest_h + 1])
					return;
			}
			std::swap(towers[src][src_h], towers[dest][dest_h]);
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
	TowerOfHanoi toh = TowerOfHanoi(5);
	toh.moveDisc(0, 1);
	toh.moveDisc(0, 2);
	toh.moveDisc(1, 2);
	toh.moveDisc(0, 1);
	toh.moveDisc(0, 1);
	toh.print();
	return 0;
}