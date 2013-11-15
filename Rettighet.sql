CREATE TABLE  Rettighet (
rettighet_id     INT(10) UNSIGNED NOT NULL AUTO_INCREMENT, 
rettigheter    VARCHAR(10) NOT NULL,
fil     INT NOT NULL,

PRIMARY KEY(rettighet_id),

FOREIGN KEY (rettigheter)
    REFERENCES ListeRettigheter(liste_id) 
    ON DELETE CASCADE,

FOREIGN KEY (fil) 
    REFERENCES Fil(fil_id)
    ON DELETE CASCADE 
);
