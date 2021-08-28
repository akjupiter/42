CREATE DATABASE wordpress CHARACTER SET UTF8 COLLATE UTF8_BIN;
CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';
FLUSH PRIVILEGES;
