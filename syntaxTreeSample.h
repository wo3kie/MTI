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
	DeclarationList* listaDeklaracji1= new DeclarationList(
		new DoubleDeclaration(
			"a", 3
		)
	);

// ** Funkcja 'swap' ***********************************************************

	ParameterList* listaParametrow1= new ParameterList(
		new ParameterList(
			new ParametrDouble(
				"a"
			)
		)
		,new ParametrDouble(
			"b"
		)
	);

	DeclarationList* listaDeklaracji2= new DeclarationList(
		new DoubleDeclaration(
			"c"
		)
	);

	ComplexInstrukction* instrukcjaZlozona1= new ComplexInstrukction(
		new OpcjonalneInstrukcje(
			new InstructionList(
				new InstructionList(
					new InstructionList(
						new InstructionList(
							new AssignmentInstruction(
								new LocalVariable(
									"c"
								)
								,new Expression(
									new SimpleExpression(
										new Unit(
											new UnaryFactor(
												new LocalVariable(
													"a"
												)
											)
										)
									)
								)
							)
						)
						,new AssignmentInstruction(
							new LocalVariable(
								"a"
							)
							,new Expression(
								new SimpleExpression(
									new Unit(
										new UnaryFactor(
											new LocalVariable(
												"b"
											)
										)
									)
								)
							)
						)
					)
					,new AssignmentInstruction(
						new LocalVariable(
							"b"
						)
						,new Expression(
							new SimpleExpression(
								new Unit(
									new UnaryFactor(
										new LocalVariable(
											"c"
										)
									)
								)
							)
						)
					)
				)
				,new ReturnInstruction(
					new Expression(
						new SimpleExpression(
							new Unit(
								new UnaryFactor(
									new LocalVariable(
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

	FunctionDefinition* definicjaFunkcji1= new FunctionDefinition(
		new DoubleValue(), "swap", listaParametrow1, listaDeklaracji2, instrukcjaZlozona1
	);

// ** Funkcja 'main' ***********************************************************

	ParameterList* listaParametrow2= new ParameterList();

	DeclarationList* listaDeklaracji3= new DeclarationList(
		new DeclarationList(
			new DoubleDeclaration(
				"a", 1
			)
		)
		,new DoubleDeclaration(
			"b", 2
		)
	);

	ComplexInstrukction* instrukcjaZlozona2= new ComplexInstrukction(
		new OpcjonalneInstrukcje(
			new InstructionList(
				new InstructionList(
					new InstructionList(
						new InstructionList(
							new AssignmentInstruction(
								new GlobalVariable(
									"a"
								)
								,new Expression(
									new SimpleExpression(
										new Unit(
											new UnaryFactor(
												new FunctionCall(
													"swap"
													, new ExpressionList(
														new ExpressionList(
															new Expression(
																new SimpleExpression(
																	new Unit(
																		new UnaryFactor(
																			new LocalVariable(
																				"a"
																			)
																		)
																	)
																)
															)
														)
														,new Expression(
															new SimpleExpression(
																new Unit(
																	new UnaryFactor(
																		new LocalVariable(
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
						,new PrintInstruction(
							new Expression(
								new SimpleExpression(
									new Unit(
										new UnaryFactor(
											new LocalVariable(
												"a"
											)
										)
									)
								)
							)
						)
					)
					,new PrintInstruction(
						new Expression(
							new SimpleExpression(
								new Unit(
									new UnaryFactor(
										new LocalVariable(
											"b"
										)
									)
								)
							)
						)
					)
				)
				,new PrintInstruction(
					new Expression(
						new SimpleExpression(
							new Unit(
								new UnaryFactor(
									new GlobalVariable(
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

	FunctionDefinition* definicjaFunkcji2= new FunctionDefinition(
		new DoubleValue(), "main",  listaParametrow2, listaDeklaracji3, instrukcjaZlozona2
	);

//** Program *******************************************************************
	FunctionList* listaFunkcji1= new FunctionList(
		new FunctionList(
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
