#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

class ManufacturingPlant {
public:
	ManufacturingPlant() : materialsCount{0} {}
	
	void receiveMaterials(int i);
	int produceProduct();
private:
	int materialsCount;
	std::mutex materialsCountMutex;
	const int CAPACITY = 100;
	std::condition_variable hasMaterials;
	std::condition_variable hasCapacity;
};

void ManufacturingPlant::receiveMaterials(int i) {
	std::unique_lock<std::mutex> lg(materialsCountMutex);
	/*if (materialsCount + i > CAPACITY) {
		// TODO: wait for capacity! 
	}*/
	hasCapacity.wait(lg, [this, &i] {
		if (materialsCount + i > CAPACITY) return false;
		return true;
	});
	std::cout << "adding materials " << materialsCount << std::endl;
	materialsCount += i;
	hasMaterials.notify_one();
}

int ManufacturingPlant::produceProduct() {
	std::unique_lock<std::mutex> lg(materialsCountMutex);
	/*if (materialsCount - 10 > 0) {
		// TODO: wait for materials to arrive
	}*/
	hasMaterials.wait(lg, [this] {
		if (materialsCount - 10 < 0) return false;
		return true;
	});
	materialsCount -= 10;
	hasCapacity.notify_one();
	return 10;
}

class Truck {
public:
	Truck(ManufacturingPlant& m) : mp{m} {}
	void deliverMaterials() {
		mp.receiveMaterials(10);
	}
private:
	ManufacturingPlant& mp;
};

class Train {
public:
	Train(ManufacturingPlant& m) : mp{m} {}
	void getProduct() {
		mp.produceProduct();
	}
private:
	ManufacturingPlant& mp;
};	

int main() {
	ManufacturingPlant plant;
	
	// create a thread to make truck delieveries.
	std::thread t1([&plant]{
		for (int i = 0; i < 1000; ++i) {
			Truck t{plant};
			t.deliverMaterials();
		}
	});
	
	// create a thread to make trains arrive.
	std::thread t2([&plant]{
		for (int i = 0; i < 1000; ++i) {
			Train t{plant};
			t.getProduct();
		}
	});
	
	// wait for threads to finish... 
	t1.join();
	t2.join();
}
