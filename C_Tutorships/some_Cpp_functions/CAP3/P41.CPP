char *F (char *s, int i) {
	char *p;

	if (i % 20 > 10)
		p = _strerror (s);
	else p = _strerror ("Error en F()");
	return (p);
}
