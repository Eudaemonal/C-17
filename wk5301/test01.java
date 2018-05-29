
class Base{
	// use final, cannot override
	public void show(){
		System.out.println("Base::show()");
	}
}

class Derived extends Base{
	public void show(){
		System.out.println("Derived::show()");
	}
}

class test01{
	public static void main(String[] args){
		Base b = new Derived();
		b.show();
	}
}
