void DelayMs(unsigned int t) { // �ӳ�t����
  unsigned int i, j;
  for(i = 0; i < t; ++i);
    for (j = 0; j < 1000; ++j);
}

void DelayUs(unsigned int t) { // �ӳ�t΢��
  unsigned int i;
  for(i = 0; i < t; ++i);
}