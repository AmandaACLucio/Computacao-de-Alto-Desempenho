program produto_matriz_vetor
    implicit none

    integer :: tamanho, funcao, tamanho_matriz

    tamanho = 40000

    do tamanho_matriz=1, tamanho, 500

        call multiplica_matriz_linha_coluna(tamanho_matriz)

    end do

    contains

        subroutine multiplica_matriz_linha_coluna(tamanho)

            implicit none

            real(8), dimension(:,:), allocatable :: matrizA
            real(8), dimension (:), allocatable :: vetorX
            real(8), dimension (:), allocatable :: vetorB 

            integer :: linha, coluna, tamanho
            real(8) :: numeroAleatorio
            real(8) :: start, finish, finish2

            !Alocando matrizes
            allocate(matrizA(tamanho, tamanho))
            allocate(vetorX(tamanho))
            allocate(vetorB(tamanho))

            call random_seed()

            ! gerando matriz com numeros Aleatórios
            
            do linha = 1, tamanho
                do coluna = 1, tamanho
                    call random_number(numeroAleatorio)
                    matrizA(linha, coluna) = numeroAleatorio * (tamanho + 1)
                end do
            end do 

            ! gerando vetor com numeros Aleatórios
            do linha = 1, tamanho
                call random_number(numeroAleatorio)
                vetorX(linha) = numeroAleatorio * (tamanho + 1)
            end do 


            !zerando
            do linha = 1, tamanho
                vetorB(linha) = 0
            end do 


            call cpu_time(start) 
    
            !multiplicando linha-coluna
            do linha =1, tamanho
                do coluna=1, tamanho
                    vetorB(linha) = vetorB(linha) +  matrizA(linha, coluna) * vetorX(coluna);
                end do
            end do

            call cpu_time(finish) 

            !multiplicando coluna-linha
            do coluna =1, tamanho
                do linha=1, tamanho
                    vetorB(linha) = vetorB(linha) +  matrizA(linha, coluna) * vetorX(coluna);
                end do
            end do

            call cpu_time(finish2) 

            print *, tamanho_matriz, ":", (finish - start)," - " , (finish2 - finish) 

            !Desalocando variaveis
            deallocate(matrizA)
            deallocate(vetorX)
            deallocate(vetorB)

        end

end program produto_matriz_vetor