int romanToInt(char* s) {
    //register int lenth = strlen(s);
	register int tmp = 0;
	/*for (int i = 0; ; i++){
		//switch (s[i])
		//{
		//case 'I'://1
		//	tmp += 1;
		//	break;
		//case 'V'://5
		//	tmp += 5;
		//	if (i> 0 && s[i - 1] == 'I')
		//		tmp -= 2;
		//	break;
		//case 'X'://10
		//	tmp += 10;
		//	if (i> 0 && s[i - 1] == 'I')
		//		tmp -= 2;
		//	break;
		//case 'L'://50
		//	tmp += 50;
		//	if (i> 0 && s[i - 1] == 'X')
		//		tmp -= 20;
		//	break;
		//case 'C'://100
		//	tmp += 100;
		//	if (i> 0 && s[i - 1] == 'X')
		//		tmp -= 20;
		//	break;
		//case 'D'://500
		//	tmp += 500;
		//	if (i> 0 && s[i - 1] == 'C')
		//		tmp -= 200;
		//	break;
		//case 'M'://1000
		//	tmp += 1000;
		//	if (i> 0 && s[i - 1] == 'C')
		//		tmp -= 200;
		//	break;
		//default:
		//	break;
		//}
		if (s[i] == 'I'){//1
			tmp += 1;
		}
		else if (s[i] == 'V'){//5
			tmp += 5;
			if (i> 0 && s[i - 1] == 'I')
				tmp -= 2;
		}
		else if (s[i] == 'X'){//10
			tmp += 10;
			if (i> 0 && s[i - 1] == 'I')
				tmp -= 2;
		}
		else if (s[i] == 'L'){//50
			tmp += 50;
			if (i> 0 && s[i - 1] == 'X')
				tmp -= 20;
		}
		else if (s[i] == 'C'){//100
			tmp += 100;
			if (i> 0 && s[i - 1] == 'X')
				tmp -= 20;
		}
		else if (s[i] == 'D'){//500
			tmp += 500;
			if (i> 0 && s[i - 1] == 'C')
				tmp -= 200;
		}
		else if (s[i] == 'M'){//1000
			tmp += 1000;
			if (i> 0 && s[i - 1] == 'C')
				tmp -= 200;
		}
		else if (s[i] == 0){//1000
		    return tmp;
		}
	}//*/
	register char *sP = s;
	do{
		switch (*sP++)
		{
		case 'I'://1
			tmp += 1;
			break;
		case 'V'://5
			if (tmp != 0 && sP[-2] == 'I')
				tmp -= 2;
			tmp += 5;
			break;
		case 'X'://10
			if (tmp != 0 && sP[-2] == 'I')
				tmp -= 2;
			tmp += 10;
			break;
		case 'L'://50
			if (tmp != 0 && sP[-2] == 'X')
				tmp -= 20;
			tmp += 50;
			break;
		case 'C'://100
			if (tmp != 0 && sP[-2] == 'X')
				tmp -= 20;
			tmp += 100;
			break;
		case 'D'://500
			if (tmp != 0 && sP[-2] == 'C')
				tmp -= 200;
			tmp += 500;
			break;
		case 'M'://1000
			if (tmp != 0 && sP[-2] == 'C')
				tmp -= 200;
			tmp += 1000;
			break;
		default:
			return tmp;
		}
	} while (true);
	return tmp;
}
