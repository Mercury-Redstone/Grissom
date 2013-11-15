CREATE TABLE Bruker(
        	bruker_id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
        	navn VARCHAR(90) NOT NULL,
        	epost VARCHAR(50) NOT NULL,
        	tlf INT(8) ZEROFILL NOT NULL,
        	adresse VARCHAR(50) NOT NULL,
        	byen VARCHAR(50) NOT NULL,
        	postkode INT(4) ZEROFILL NOT NULL,
        	gender ENUM('M','F') NOT NULL DEFAULT 'M',
       	PRIMARY KEY(bruker_id)
);
