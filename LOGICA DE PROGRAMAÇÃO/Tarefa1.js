//questao 1 

<script>
    
var lugara, lugarb, PG , LG, RG; // declarando as variaveis em q PG é a gaslina, LG sao os litros gasto e RG sao reais gasto

lugara =parseInt(prompt("digite onde estar")) // PEDINDO O VALOR DO KM DO LUGAR EM QUE ESTAR
lugarb =parseInt(prompt("digite ate onde vai")) // VALOR DO KM ATE ONDE VAI 
PG =parseFloat(prompt("digite o valor da gasolina")) // VALOR DA GASOLINA ONDE IRA ABASTECER 

LG = (lugarb - lugara) / 12 // CALCULO PARA SABER QUANTOS LITROS SERA NECESSARIO PARA A VIAGEM
RG = PG*LG // CALCULO PARA SABER O DINHEIRO GASTO, A QUANTIA DA GASOLINA POR LITRO VEZES OS LITROS 

alert ("o carro vai gastar de litros" + LG) // RESULTADO DOS LITROS GASTOS
alert ("o carro ira gastar de Reais " + RG) // RESULTADO DO DINHEIRO GASTO  

</script>

// questao 2 

<script>
var salario , plano, x // DECLARANDO AS VARIAVEIS 

salario= parseInt(prompt("digite o valor do salario")) // O SALARIO DO FUNCIONARIO 
do{ // USANDO O DO WHILE PARA QUE O USUARIO NAO POSSA SAIR DELE ATE QUE DIGITE AS 3 OPÇOES Q APARECE, E ASSIM ESCOLHERA UM NUMERO QUE VAI ENTRAR NA CONDIÇAO DO "IF" E MOSTRARA O PLANO
	x= parseInt(prompt("digite 1 para o plano A, 2 Para o plano B, 3 Para o plano C")) 
} while(x<=0 || x>=4) 
planoA = (salario*0.10) + salario // VALOR DO PLANO A
planoB = (salario*0.15) + salario // VALOR DO PLANO B
planoC = (salario*0.25) + salario // VALOR DO PLANO C 



if(x==1){ // CONDIÇAO Q QUANDO O USUARIO QUERER O PLANO A, VAI DIGITAR NO DO WHILE O NUMERO 1  
	alert("seu novo salario sera de" +planoA) 
	}
if(x==2){ // CONDIÇAO Q QUANDO O USUARIO QUERER O PLANO B, VAI DIGITAR NO DO WHILE O NUMERO 2 
	alert("seu novo salario sera de" +planoB)
}
if(x==3) { // CONDIÇAO Q QUANDO O USUARIO QUERER O PLANO C, VAI DIGITAR NO DO WHILE O NUMERO 3
	alert("seu novo salario sera de" +planoC)
}
	

</script>

//questao 3 


<script>
var x, i=0 // DECLARANDO A VARIAVEL E O CONTADOR    

x=parseInt(prompt("digite um numero inteiro")) // O USUARIO DIGITAR O NUMERO QUE QUER 

while(x>=0){ // SE ELE FOR IGUAL OU MAIOR QUE ZERO ENTRA NA CONDIÇAO, SE FOR NEGATIVO O PROGRAMA PARA
	i=i+x // IRA SOMAR OS NUMEROS DIGITADOS PELO USUARIO 
	
	x=parseInt(prompt("digite um numero inteiro")) // ATE O USUARIO DIGITAR UM NUMERO NEGATIVO, IRA APARECER A OPÇAO NOVAMENTE PARA ELE COLOCAR UM NUMERO INTEIRO
	}
	 
	if(i%2==0) { //PEGANDO O VALOR DA SOMA E CALCULANDO O RESTO DA DIVISAO POR 2 
		alert("a soma dos numeros inteiros sao par")// SE O RESTO FOR 0, IRA APARECER QUE A SOMA FOI PAR
	}
	
	else{ 
		alert("a soma dos numeros inteiros sao impar")// SE O RESTO FOR DIFERENTE DE 0,IRA APARECER QUE A SOMA FOI IMPAR
	}
	
</script>



//questao 4 

<SCRIPT>

  var x,cont=0 // DECLARANDO AS VARIAVEIS  

  do{ // PARA QUE O USUARIO FIQUE DIGITANDO , ATE ELE DIGITAR UM NUMERO MAIOR QUE ZERO
	  x=parseInt(prompt("digite um numero")) 
  }while  (x<=0)

  i=x // O i IRA TAMBEM RECEBER O NUMERO DIGITADO 
  while (i>0) { 
	    if (x%i==0) { 
		    cont++ // IRA CONTAR QUANTOS DIVISORES O NUMERO TEM
	    }
	    i-- // IRA FICAR TESTANDO OS NUMEROS NA ORDEM DECRESCENTE DO VALOR DIGITADO, ATE Q SE TENHA UM DIVISOR
  }
   if (cont==2) { // SE FOR IGUAL A 2, IRA APARECER Q O NUMERO SERA PRIMO. POIS O NUMERO É DIVISIVEL SO POR 1 E POR ELE MESMO
	   alert("é primo")
   }
   else {
	   alert(" nao é primo") // SE FOR DIFERENTE DE 2,IRA APARECER Q ELE NAO SERA PRIMO
   }

</SCRIPT>