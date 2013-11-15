CREATE TABLE Fil(
    fil_id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, 
    filNavn    VARCHAR(30) NOT NULL, 
    bruker_id INT NOT NULL DEFAULT 0,
    gruppe_id INT NOT NULL DEFAULT 0, 
    katalog_id INT NOT NULL, 
    eier    INT NOT NULL DEFAULT 1, 
    skal_overvake TINYINT(1) NOT NULL DEFAULT 0,

    PRIMARY KEY(fil_id),

    FOREIGN KEY(bruker_id)    
	REFERENCES Bruker(bruker_id)
	ON DELETE SET DEFAULT,

    FOREIGN KEY(gruppe_id) 
	REFERENCES Gruppe(gruppe_id) 
	ON DELETE SET DEFAULT,

    FOREIGN KEY(katalog_id) 
	REFERENCES Katalog(katalog_id) 
	ON DELETE CASCADE,

    FOREIGN KEY(eier)
	REFERENCES Bruker(bruker_id) 
	ON DELETE SET DEFAULT
    );
