#include <stdio.h>

char* hex_to_bits(char hex){
	switch(hex){
		case '1':
			return "1000";
		break;
		case '2':
			return "0100";
		break;
		case '3':
			return "1100";
		break;
		case '4':
			return "0010";
		break;
		case '5':
			return "1010";
		break;
		case '6':
			return "0110";
		break;
		case '7':
			return "0110";
		break;
		case '8':
			return "0001";
		break;
		case '9':
			return "1001";
		break;
		case 'A':
			return "0101";
		break;
		case 'B':
			return "1101";
		break;
		case 'C':
			return "0011";
		break;
		case 'D':
			return "1011";
		break;
		case 'E':
			return "0111";
		break;
		case 'F':
			return "1111";
		break;
		default:
			return "0000";
	}
}



float a;

void printA(){
	char tmp[17];
	char tmp2[70];
	sprintf(tmp, "%X", *(unsigned*)&a);
	sprintf(tmp2, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", hex_to_bits(tmp[0]), hex_to_bits(tmp[1]), hex_to_bits(tmp[2]), hex_to_bits(tmp[3]), hex_to_bits(tmp[4]), hex_to_bits(tmp[5]), hex_to_bits(tmp[6]), hex_to_bits(tmp[7]), hex_to_bits(tmp[8]), hex_to_bits(tmp[9]), hex_to_bits(tmp[10]), hex_to_bits(tmp[11]), hex_to_bits(tmp[12]), hex_to_bits(tmp[13]), hex_to_bits(tmp[14]), hex_to_bits(tmp[15]), hex_to_bits(tmp[16]));
	
	printf("Decimal: %f Hex: %s Bin: %s \n", a, tmp, tmp2);
}

int main(){
	a = 0.0;
	printA();
	a = 1.0;
	printA();
	a = -1.25;
	printA();

	return 0;
}
