bool isprime(long long N) {
	// N �� 2 �ȏ�̐����Ƃ��AN ���f���ł���� true�A�f���łȂ���� false ��Ԃ�
	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}