#include <iostream>
#include <bitset>
using namespace std;

int exponent(string bstr, int n_exponent){
	for(int i=0; i<bstr.length();i++){
		if(bstr[i]=='1') return n_exponent;
		n_exponent--;
	}
	return 0;
}

template <class V>

string ent_a_bin(V n, int conv=0){
	
	
	if (sizeof(n)==4 || sizeof(n)==8){

		string output, bstr;
		int n_exponent, n_significand;
		
		if (n < 0){
			output = "1 ";
			n *= 1;
		}
		else output = "0 ";

		if (n<256 && conv==0){
			
			bitset<8> binary_32(n);
			bstr = binary_32.to_string();
			n_significand = 23;
			n_exponent = exponent(bstr, 7);
			bstr = bstr.substr(8-n_exponent);
			
			if (n_exponent!=0) n_exponent += 127;
			
			binary_32 = n_exponent;
			output += binary_32.to_string();
		}
		else if ((n>255 && n<2048) || conv==1){
			
			bitset<11> binary_64(n);
			bstr = binary_64.to_string();
			n_significand = 52;
			n_exponent = exponent(bstr, 10);
			bstr = bstr.substr(11-n_exponent);
			
			if (n_exponent!=0) n_exponent += 1023;

			binary_64 = n_exponent;
			output += binary_64.to_string();
		}
		else if((n>2047 && n<32768) || conv==2){
			
			bitset<15> binary_128(n);
			bstr = binary_128.to_string();
			n_significand = 112;
			n_exponent = exponent(bstr, 14);
			bstr = bstr.substr(15-n_exponent);
			
			if (n_exponent!=0) n_exponent += 16383;

			binary_128 = n_exponent;
			output += binary_128.to_string();
		}
		
		output += ".";
		output += bstr;
		
		int int_n = n;
		V significand = n - int_n;
		n_significand -= bstr.length();
		
		return output;
	}
	
	return "error";
}

int main(){
	float a = 58.76, e = 12500.55;
	double b = 301.91, ba = a; 
	int c = 17;
	char d = '@';
	
	string binary_n = ent_a_bin(a);
	cout<<" binario de ("<<a<<") = "<<binary_n<<endl<<endl;

	binary_n = ent_a_bin(b);
	cout<<" binario de ("<<b<<") = "<<binary_n<<endl<<endl;
	
	binary_n = ent_a_bin(c);
	cout<<" binario de ("<<c<<") = "<<binary_n<<endl<<endl;

	binary_n = ent_a_bin(d);
	cout<<" binario de ("<<d<<") = "<<binary_n<<endl<<endl;

  return 0;
	
}