// questao 1

<script>
	var x // declarando a variavel 
	do{ // condiçao para que o usuario fique digitando, ate digitar um valor positivo
		x=parseInt(prompt("digite um valor inteiro")) // valor de x 
	}while (x<=0)
	i=x // outra variavel recebe o valor de x 
	
	while (i>0){ // se o valor for maior que 0, entra na condiçao 
		
		  if (x%i==0 && i%2!=0){ // se o resto da divisao de x por i for igual a zero, o numero é seu divisor. E se o resto do divisor que é i, divido por 2, for difernte de 0, o numero é impar 
			         alert(i) // ira mostrar os valores que passou na condiçao do 'if', 
		         }
		  i-- // vai diminuindo, para pode testar todos os numeros abaixo de x, e no if saber se o numero do momento é divisor e tambem impar 
	}
</script>




// questao 2
<script>

	var x,y,i // declarando as variaveis 
	
	do{ // como tem que ser um intervalo de x ate y , o valor de y tem q ser maior. entao so vai passar do dowhile quando y for maior q x 
	x=parseInt(prompt("digite o primeiro numero")) // valor de x 
	y=parseInt(prompt("digite o segundo numero")) // valor de y 
	} while(y<x)
	i=x // outra variavel recebe o valor de x 
	
	while(i<=y){ // enquanto o valor de i for menor que y, vai entrar na condiçao 
		if(i%3==0){ // vai testar se o valor entre x e y é divisivel por 3 
			alert(i) // aki ira aparecer os numeros da condiçao anterior, a tela vai mostrar um por um, os numeros que satisfazem o 'if'
		}
		i++ // vai aumentando o numero para pode calcular todos os numeros entre x e y, no if ira mostrar os q sao divisiveis por 3, 
		    // e quando o i chegar a ser maior que o y, nao entra na condiçao do while. ate pq estara fora do intervalo 
	}
</script>

// questao 3
<script>

	var alunos,n1,n2,n3,media,por,cont=0 // declarando as variaveis 
	
	do{ // como nao existe numero de aluno negativo, so vai entrar na condiçao quando digitar numero maior que zero 
	alunos=parseInt(prompt("quantos alunos?"))
	} while(alunos<0)
	i=0
	while(i<alunos){ // enquanto i for menor que a quantidade de alunos, vai ficar testando as notas de cada aluno. 
	do{ // so vai aceitar notas acima de zero, e abaixo de 10. enquanto nao digitar a nota entre esses valores, o programa n continua 
		n1=parseInt(prompt("digite a primeira nota"))
	} while(n1<0 || n1>10)
	do{ // so vai aceitar notas acima de zero, e abaixo de 10. enquanto nao digitar a nota entre esses valores, o programa n continua
		n2=parseInt(prompt("digite a segunda nota"))
	} while(n2<0 || n2>10)
	do{ // so vai aceitar notas acima de zero, e abaixo de 10. enquanto nao digitar a nota entre esses valores, o programa n continua
		n3=parseInt(prompt("digite a terceira nota"))
	} while(n3<0 || n3>10)
	media=(n1+n2+n3)/3 // calculando a media do tal aluno 
	i++ // ira ficar somando para que quando chegar na quantidade acima da que foi pedida pelo usuario, nao calcula mais notas. 
	if(media>=5 && media<=10){ // calcular a media, para saber quem foi aprovado 
		 cont++ // calcula quantos foram aprovados 
	}
}
	por=(cont/alunos)*100 // calculo para descobrir a porcetagem de aprovados 
	alert(" a porcentagem de aprovados sao " + por + "%") // mensagem q ira mostrar a porcentagem de aprovados 
</script>


// questao 4

<script>
	var x,y,i,soma=0,media // declarando as variaveis 
	
	do{  //como tem que ser um intervalo de x ate y , o valor de y tem q ser maior. entao so vai passar do dowhile quando y for maior q x 
	x=parseInt(prompt("digite um numero")) // valor de x 
	y=parseInt(prompt("digite um numero")) // valor de y 
	} while(y<x)
	i=x // outra variavel recebe o valor de x 
		while(i<=y){ // enquanto o i for menor que y, vai entrar na condiçao 
			soma=i+soma // somar todos os valores que estao dentro do intervalo 
			i++ // vai fazer com que cada numero entre x e y, entre na somatoria 
		}
		media=soma/(y-x)// a media sera a soma de todos os valores, dividindo pela quantidade de numeros entre x e y 
		alert ("media dos numeros no intervalo e " + media) // ira mostrar o valor da media 
</script>