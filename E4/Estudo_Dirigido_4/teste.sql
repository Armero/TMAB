select pessoa.Nm_Pessoa, professor.Ds_titulo, professor.Nu_SIAPE
from pessoa
inner join professor
on pessoa.Cd_Pessoa = professor.Cd_Pessoa;