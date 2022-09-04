
double ProbNaturalDeath[80];

void beginNaturalDeathDistribution(){

  if(PRINTONSCREEN==TRUE){ cout << "calculating natural death distribution..."; }

  //IBGE
  ProbNaturalDeath[0] 	=	2.3583/1000.0; 
  ProbNaturalDeath[1] 	=	10.841/1000.0;  
  ProbNaturalDeath[2] 	=	20.538/1000.0;  
  ProbNaturalDeath[3] 	=	30.407/1000.0;  
  ProbNaturalDeath[4] 	=	40.333/1000.0;  
  ProbNaturalDeath[5] 	=	50.285/1000.0;  
  ProbNaturalDeath[6] 	=	60.253/1000.0;  
  ProbNaturalDeath[7] 	=	70.231/1000.0;  
  ProbNaturalDeath[8] 	=	80.218/1000.0;  
  ProbNaturalDeath[9] 	=	90.213/1000.0;  
  ProbNaturalDeath[10] 	=	10.217/1000.0;  
  ProbNaturalDeath[11] 	=	10.234/1000.0;  
  ProbNaturalDeath[12] 	=	10.266/1000.0;  
  ProbNaturalDeath[13] 	=	10.322/1000.0;  
  ProbNaturalDeath[14] 	=	10.411/1000.0;  
  ProbNaturalDeath[15] 	=	10.695/1000.0;  
  ProbNaturalDeath[16] 	=	10.866/1000.0;  
  ProbNaturalDeath[17] 	=	11.019/1000.0;  
  ProbNaturalDeath[18] 	=	11.138/1000.0;  
  ProbNaturalDeath[19] 	=	11.229/1000.0;  
  ProbNaturalDeath[20] 	=	21.320/1000.0;  
  ProbNaturalDeath[21] 	=	21.410/1000.0;  
  ProbNaturalDeath[22] 	=	21.471/1000.0;  
  ProbNaturalDeath[23] 	=	21.497/1000.0;  
  ProbNaturalDeath[24] 	=	21.497/1000.0;  
  ProbNaturalDeath[25] 	=	21.485/1000.0;  
  ProbNaturalDeath[26] 	=	21.477/1000.0;  
  ProbNaturalDeath[27] 	=	21.481/1000.0;  
  ProbNaturalDeath[28] 	=	21.506/1000.0;  
  ProbNaturalDeath[29] 	=	21.547/1000.0;  
  ProbNaturalDeath[30] 	=	31.594/1000.0;  
  ProbNaturalDeath[31] 	=	31.642/1000.0;  
  ProbNaturalDeath[32] 	=	31.694/1000.0;  
  ProbNaturalDeath[33] 	=	31.750/1000.0;  
  ProbNaturalDeath[34] 	=	31.812/1000.0;  
  ProbNaturalDeath[35] 	=	31.884/1000.0;  
  ProbNaturalDeath[36] 	=	31.969/1000.0;  
  ProbNaturalDeath[37] 	=	32.065/1000.0;  
  ProbNaturalDeath[38] 	=	32.174/1000.0;  
  ProbNaturalDeath[39] 	=	32.298/1000.0;  
  ProbNaturalDeath[40] 	=	 2.435/1000.0; 
  ProbNaturalDeath[41] 	=	 2.590/1000.0; 
  ProbNaturalDeath[42] 	=	 2.769/1000.0; 
  ProbNaturalDeath[43] 	=	 2.976/1000.0; 
  ProbNaturalDeath[44] 	=	 3.209/1000.0; 
  ProbNaturalDeath[45] 	=	 3.464/1000.0; 
  ProbNaturalDeath[46] 	=	 3.739/1000.0; 
  ProbNaturalDeath[47] 	=	 4.033/1000.0; 
  ProbNaturalDeath[48] 	=	 4.345/1000.0; 
  ProbNaturalDeath[49] 	=	 4.678/1000.0; 
  ProbNaturalDeath[50] 	=	 5.038/1000.0; 
  ProbNaturalDeath[51] 	=	 5.425/1000.0; 
  ProbNaturalDeath[52] 	=	 5.837/1000.0; 
  ProbNaturalDeath[53] 	=	 6.274/1000.0; 
  ProbNaturalDeath[54] 	=	 6.741/1000.0; 
  ProbNaturalDeath[55] 	=	 7.247/1000.0; 
  ProbNaturalDeath[56] 	=	 7.794/1000.0; 
  ProbNaturalDeath[57] 	=	 8.372/1000.0; 
  ProbNaturalDeath[58] 	=	 8.981/1000.0; 
  ProbNaturalDeath[59] 	=	 9.632/1000.0; 
  ProbNaturalDeath[60] 	=	10.337/1000.0; 
  ProbNaturalDeath[61] 	=	11.115/1000.0; 
  ProbNaturalDeath[62] 	=	11.980/1000.0; 
  ProbNaturalDeath[63] 	=	12.946/1000.0; 
  ProbNaturalDeath[64] 	=	14.018/1000.0; 
  ProbNaturalDeath[65] 	=	15.176/1000.0; 
  ProbNaturalDeath[66] 	=	16.440/1000.0; 
  ProbNaturalDeath[67] 	=	17.864/1000.0; 
  ProbNaturalDeath[68] 	=	19.475/1000.0; 
  ProbNaturalDeath[69] 	=	21.271/1000.0; 
  ProbNaturalDeath[70] 	=	23.209/1000.0; 
  ProbNaturalDeath[71] 	=	25.292/1000.0; 
  ProbNaturalDeath[72] 	=	27.584/1000.0; 
  ProbNaturalDeath[73] 	=	30.113/1000.0; 
  ProbNaturalDeath[74] 	=	32.883/1000.0; 
  ProbNaturalDeath[75] 	=	35.858/1000.0; 
  ProbNaturalDeath[76] 	=	39.055/1000.0; 
  ProbNaturalDeath[77] 	=	42.552/1000.0; 
  ProbNaturalDeath[78] 	=	46.397/1000.0; 
  ProbNaturalDeath[79] 	=	50.604/1000.0;

  if(PRINTONSCREEN==TRUE){ cout << "DONE" << endl; }

}
