CREATE TABLE  Endring(
    e_id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
    fil_id VARCHAR(50) NOT NULL,
    hash VARCHAR(128) NOT NULL,
    dato DATETIME NOT NULL,
    generasjon TINYINT UNSIGNED NOT NULL,
FOREIGN KEY(fil_id)
REFERENCES Fil(fil_id) 
ON DELETE CASCADE,
    PRIMARY KEY(e_id)
 );
