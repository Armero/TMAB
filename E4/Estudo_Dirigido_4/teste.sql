select pessoa.Nm_Pessoa, professor.Ds_titulo, professor.Nu_SIAPE
from pessoa
inner join professor
on pessoa.Cd_Pessoa = professor.Cd_Pessoa;

select pessoa.Nm_Pessoa, aluno.Nu_Dre
from pessoa
inner join aluno
on pessoa.Cd_Pessoa = aluno.Cd_Pessoa;