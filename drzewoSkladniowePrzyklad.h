/*
	Drzewo sk³adniowe zbudowane rêcznie dla przyk³adowego programu
*/

/*

int main() {

	/*
		double a= 3;

		double swap( double a, double b)
			double c;
		{
			c=a;
			a=b;
			b=c;
			return b;
		}

		double main()
			double a=1;
			double b=2;
		{
			::a= swap( a, b);
			printf( a);
			printf( b);
			printf( ::a);
		}
	* /

// ** Zmienna globalna *********************************************************
	ListaDeklaracji* listaDeklaracji1= new ListaDeklaracji(
		new DeklaracjaDouble(
			"a", 3
		)
	);

// ** Funkcja 'swap' ***********************************************************

	ListaParametrow* listaParametrow1= new ListaParametrow(
		new ListaParametrow(
			new ParametrDouble(
				"a"
			)
		)
		,new ParametrDouble(
			"b"
		)
	);

	ListaDeklaracji* listaDeklaracji2= new ListaDeklaracji(
		new DeklaracjaDouble(
			"c"
		)
	);

	InstrukcjaZlozona* instrukcjaZlozona1= new InstrukcjaZlozona(
		new OpcjonalneInstrukcje(
			new ListaInstrukcji(
				new ListaInstrukcji(
					new ListaInstrukcji(
						new ListaInstrukcji(
							new InstrukcjaPrzypisania(
								new ZmiennaLokalna(
									"c"
								)
								,new Wyrazenie(
									new ProsteWyrazenie(
										new Skladnik(
											new CzynnikUnarny(
												new ZmiennaLokalna(
													"a"
												)
											)
										)
									)
								)
							)
						)
						,new InstrukcjaPrzypisania(
							new ZmiennaLokalna(
								"a"
							)
							,new Wyrazenie(
								new ProsteWyrazenie(
									new Skladnik(
										new CzynnikUnarny(
											new ZmiennaLokalna(
												"b"
											)
										)
									)
								)
							)
						)
					)
					,new InstrukcjaPrzypisania(
						new ZmiennaLokalna(
							"b"
						)
						,new Wyrazenie(
							new ProsteWyrazenie(
								new Skladnik(
									new CzynnikUnarny(
										new ZmiennaLokalna(
											"c"
										)
									)
								)
							)
						)
					)
				)
				,new InstrukcjaSkokuReturn(
					new Wyrazenie(
						new ProsteWyrazenie(
							new Skladnik(
								new CzynnikUnarny(
									new ZmiennaLokalna(
										"b"
									)
								)
							)
						)
					)
				)
			)
		)
	);

	DefinicjaFunkcji* definicjaFunkcji1= new DefinicjaFunkcji(
		new WartoscDouble(), "swap", listaParametrow1, listaDeklaracji2, instrukcjaZlozona1
	);

// ** Funkcja 'main' ***********************************************************

	ListaParametrow* listaParametrow2= new ListaParametrow();

	ListaDeklaracji* listaDeklaracji3= new ListaDeklaracji(
		new ListaDeklaracji(
			new DeklaracjaDouble(
				"a", 1
			)
		)
		,new DeklaracjaDouble(
			"b", 2
		)
	);

	InstrukcjaZlozona* instrukcjaZlozona2= new InstrukcjaZlozona(
		new OpcjonalneInstrukcje(
			new ListaInstrukcji(
				new ListaInstrukcji(
					new ListaInstrukcji(
						new ListaInstrukcji(
							new InstrukcjaPrzypisania(
								new ZmiennaGlobalna(
									"a"
								)
								,new Wyrazenie(
									new ProsteWyrazenie(
										new Skladnik(
											new CzynnikUnarny(
												new WywolanieFunkcji(
													"swap"
													, new ListaWyrazen(
														new ListaWyrazen(
															new Wyrazenie(
																new ProsteWyrazenie(
																	new Skladnik(
																		new CzynnikUnarny(
																			new ZmiennaLokalna(
																				"a"
																			)
																		)
																	)
																)
															)
														)
														,new Wyrazenie(
															new ProsteWyrazenie(
																new Skladnik(
																	new CzynnikUnarny(
																		new ZmiennaLokalna(
																			"b"
																		)
																	)
																)
															)
														)
													)
												)
											)
										)
									)
								)
							)
						)
						,new InstrukcjaDrukowania(
							new Wyrazenie(
								new ProsteWyrazenie(
									new Skladnik(
										new CzynnikUnarny(
											new ZmiennaLokalna(
												"a"
											)
										)
									)
								)
							)
						)
					)
					,new InstrukcjaDrukowania(
						new Wyrazenie(
							new ProsteWyrazenie(
								new Skladnik(
									new CzynnikUnarny(
										new ZmiennaLokalna(
											"b"
										)
									)
								)
							)
						)
					)
				)
				,new InstrukcjaDrukowania(
					new Wyrazenie(
						new ProsteWyrazenie(
							new Skladnik(
								new CzynnikUnarny(
									new ZmiennaGlobalna(
										"a"
									)
								)
							)
						)
					)
				)
			)
		)
	);

	DefinicjaFunkcji* definicjaFunkcji2= new DefinicjaFunkcji(
		new WartoscDouble(), "main",  listaParametrow2, listaDeklaracji3, instrukcjaZlozona2
	);

//** Program *******************************************************************
	ListaFunkcji* listaFunkcji1= new ListaFunkcji(
		new ListaFunkcji(
			definicjaFunkcji1
		)
		,definicjaFunkcji2
	);

	Program* program1= new Program(
		listaDeklaracji1, listaFunkcji1
	);

	program1->execute();
}

*/
