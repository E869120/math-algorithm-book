bool isprime(long long N) {
	// N �� 2 �ȏ�̐����Ƃ��AN ���f���ł���� true�A�f���łȂ���� false ��Ԃ�
	for (long long i = 2; i <= N - 1; i++) {
		// N �� i �Ŋ���؂ꂽ�ꍇ�A���̎��_�őf���ł͂Ȃ��ƕ�����
		if (N % i == 0) return false;
	}
	return true;
}