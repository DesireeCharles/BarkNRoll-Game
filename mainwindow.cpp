#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ZorkUL game;
    console = ui->textConsole;
    consoleGUI = ui->textConsoleGUI;
    QPixmap initialImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/athena.png");
    ui->image->setPixmap(initialImage);
    gameIsStarted = false;

    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::on_textEdit_textChanged);

    QObject::connect(ui->startGame, &QPushButton::pressed, this, &MainWindow::onStartGameButtonPressed);

    QObject::connect(ui->commandsButton, &QPushButton::pressed, this, &MainWindow::oncommandsButtonPressed);

    QObject::connect(ui->mapButton, &QPushButton::pressed, this, &MainWindow::onMapButtonPressed);

    QObject::connect(ui->upButton, &QPushButton::pressed, this, &MainWindow::onupButtonPressed);

    QObject::connect(ui->rightButton, &QPushButton::pressed, this, &MainWindow::onrightButtonPressed);

    QObject::connect(ui->downButton, &QPushButton::pressed, this, &MainWindow::ondownButtonPressed);

    QObject::connect(ui->leftButton, &QPushButton::pressed, this, &MainWindow::onleftButtonPressed);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendTextToConsole(const QString& text){
    console->append(text); //updates

}

void MainWindow::appendTextToConsoleGUI(const QString& text){
    consoleGUI->append(text); //instructions
}



void MainWindow::appendTextToinventory(const QString& text){
    inventory->append(text); //inventory

}




void MainWindow::onStartGameButtonPressed(){
    gameIsStarted = true;
    findForNextRoom("start");
    QString qstr1 = QString::fromStdString(game.printWelcome());
    appendTextToConsoleGUI(qstr1);
    displayLocationDesc();

}

void MainWindow::oncommandsButtonPressed() {
    if(gameIsStarted){
        Command command("info", "");
        std::string helpText = game.processCommand(command);
        QString qstr = QString::fromStdString(helpText);
        appendTextToConsole(qstr);
    }
    else return;
}

void MainWindow::onMapButtonPressed() {
    if(gameIsStarted){
        Command command("map", "");
        std::string mapText = game.processCommand(command);
        QString qstr = QString::fromStdString(mapText);
        appendTextToConsole(qstr);
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/Map.png");
        ui->map->setPixmap(image);
    }
    else return;
}

void MainWindow::on_exit_button_pressed()
{
    qApp->quit();
}



void MainWindow::on_textEdit_textChanged()
{
    QString input = ui->textEdit->toPlainText().trimmed().toLower();
    if (input == "start"){
        gameIsStarted = true;
        findForNextRoom("start");
        QString qstr1 = QString::fromStdString(game.printWelcome());
        appendTextToConsoleGUI(qstr1);
        displayLocationDesc();
    }
    else if (input == "exit")
    {
        qApp->quit();
    }
    else if(gameIsStarted && input == "map" ){
        Command command("map", "");
        std::string mapText = game.processCommand(command);
        QString qstr = QString::fromStdString(mapText);
        appendTextToConsole(qstr);
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/Map.png");
        ui->map->setPixmap(image);
        ui->textEdit->clear();
    }
    else if(gameIsStarted && input == "commands"){
        Command command("info", "");
        std::string helpText = game.processCommand(command);
        QString qstr = QString::fromStdString(helpText);
        appendTextToConsole(qstr);
        ui->textEdit->clear();
    }
    else if (gameIsStarted && input == "up" )
    {
        Command command("go", "up");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();
        ui->textEdit->clear();


    }
    else if (gameIsStarted && input == "right")
    {
        Command command("go", "right");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();
        ui->textEdit->clear();
    }
    else if (gameIsStarted && input == "down" )
    {
        Command command("go", "down");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();
        ui->textEdit->clear();
    }
    else if (gameIsStarted && input == "left" )
    {
        Command command("go", "left");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();
        ui->textEdit->clear();
    }
    else if (gameIsStarted && input == "yes" ){
        if(gameIsStarted && game.checkRoom() == "Gloomweavers" ){
            appendTextToConsole( "Well done! You've dispelled the dark magic misconception about dogs.\n"
                                " Instead of weaving webs, they're busy perfecting their skills in tail-wagging and belly rubs.");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happydog.png");
            ui->map->setPixmap(image); // no space to put another image display, so display in the map box
            ui->textEdit->clear();
        }
        else if(gameIsStarted && game.checkRoom() == "Embermaws" ){
            appendTextToConsole("You did it! Raccoons don't leave fiery trails but they do leave a trail of mischief and trash can raiding.\n"
                                " Keep your snacks secure!");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happyraccoon.png");
            ui->map->setPixmap(image);
            ui->textEdit->clear();
        }
        else if(gameIsStarted && game.checkRoom() == "Wispfiends" ){
            appendTextToConsole("Moo-velous! You've discovered that cows are not ethereal phasers.\n"
                                " They'd rather focus on grazing grass, producing milk, and maybe even learning a few dance moves.");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happycow.png");
            ui->map->setPixmap(image);
            ui->textEdit->clear();
        }
        else if(gameIsStarted && game.checkRoom() == "Mindflayers" ){
            appendTextToConsole("Bravo! You've seen through the psychic illusion surrounding pandas. \n"
                                "Their true power lies in capturing hearts worldwide with their cuddly cuteness and bamboo-munching skills.");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happypanda.png");
            ui->map->setPixmap(image);
            ui->textEdit->clear();
        }
        else if(gameIsStarted && game.checkRoom() == "Chronomancers" ){
            appendTextToConsole("Congratulations! You've correctly uncovered the time-manipulating secrets of cats.\n"
                                " Now they can teach you the art of napping through the ages!");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happycat.png");
            ui->map->setPixmap(image);
            ui->textEdit->clear();
        }
        else if(gameIsStarted && game.checkRoom() == "Boss" ){
            appendTextToConsole("Incredible! Hamsters aren't reality-bending cosmic beings. \n"
                                "Instead, they excel at running on wheels and stuffing their cheeks with food. The cutest little adventurers!");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happyhamster.png");
            ui->map->setPixmap(image);
            ui->textEdit->clear();
        }
    }
    else if (gameIsStarted && input == "no" )
    {   if(gameIsStarted && game.checkRoom() == "Gloomweavers" ){
            appendTextToConsole("Oops! The dark magic web of misconception ensnares you. \n"
                                "The Gloomweaver dog absorbs your energy, leaving you weakened and defenseless. \n"
                                "Time to retreat and study up on doggy myths!\n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/saddog.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
        else if(gameIsStarted && game.checkRoom() == "Embermaws" ){
            appendTextToConsole("Watch out! The fiery path of the Embermaw raccoon proves too hot for you to handle.\n"
                                " You find yourself engulfed in flames, taking damage as the raccoon scurries away victoriously. \n"
                                "Keep your cool next time!\n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadraccoon.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
        else if(gameIsStarted && game.checkRoom() == "Wispfiends" ){
            appendTextToConsole("Moo-ve along! Your knowledge about cow phasing isn't quite on point. \n"
                                "The Wispfiend cow effortlessly slips through walls and disappears, leaving you in a bewildered daze.\n"
                                " Keep chasing those elusive answers!\n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadcow.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
        else if(gameIsStarted && game.checkRoom() == "Mindflayers" ){
            appendTextToConsole("Oh dear! Your mind has been skillfully manipulated by the Mindflayer panda. \n"
                                "Confusion takes over as you find yourself attacking your allies or unable to attack at all.\n"
                                " The panda triumphs, but don't lose hope!\n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadpanda.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
        else if(gameIsStarted && game.checkRoom() == "Chronomancers" ){
            appendTextToConsole( "Oh no! Your understanding of cat chronomancy needs some work. \n"
                                "The Chronomancer cat seizes the opportunity and speeds away, leaving you behind in a time warp of confusion.\n"
                                " Better luck next time! \n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadcat.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
        else if(gameIsStarted && game.checkRoom() == "Boss" ){
            appendTextToConsole( "Oh my! The cosmic powers of the Titan of Time and Space hamster are too overwhelming for you. \n"
                                "The fabric of reality warps, and you're transported to another dimension, defeated for now. \n"
                                "Keep exploring the mysteries of hamsters!\n"
                                "__________________________________________ \n"
                                "Press 'Start game' button, to start again");
            QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadhamster.png");
            ui->map->setPixmap(image);
            gameIsStarted = false;
            ui->textEdit->clear();

        }
    }
    else if (gameIsStarted && input == "drop" ){
        game.inventory.clear();
        ui->textinventory->clear();
        ui->textEdit->clear();
    }
    else return;
}


void MainWindow::onupButtonPressed() {
    if(gameIsStarted){
        Command command("go", "up");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();

    }
    else return;
}

void MainWindow::onrightButtonPressed() {
    if(gameIsStarted){
        Command command("go", "right");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();

    }
    else return;
}

void MainWindow::ondownButtonPressed() {
    if(gameIsStarted){
        Command command("go", "down");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();

    }
    else return;
}

void MainWindow::onleftButtonPressed() {
    if(gameIsStarted){
        Command command("go", "left");
        nextRoom = game.processCommand(command);
        findForNextRoom(nextRoom);
        displayLocationDesc();

    }
    else return;
}

void MainWindow::displayLocationDesc(){
    QString qstr = QString::fromStdString(game.getCurrentRoomDesc() + "items in room:  " + game.getCurrentRoomItems() + "\n" + game.getCurrentRoomExits() + "\n");
    appendTextToConsole(qstr);
}

void MainWindow::setCoverImage(){
    QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/athena.png");
    ui->image->setPixmap(image);
}

void MainWindow::findForNextRoom(string room){
    if(room == "start"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/athena.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Gloomweavers"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Gloomweavers.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Embermaws"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Embermaws.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Mindflayers"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Mindflayers.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Wispfiends"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Wispfiends.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Chronomancers"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Chronomancers.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Boss"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Boss.png");
        ui->image->setPixmap(nextImage);
    }
    else if(room == "Safe1"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Safe.png");
        ui->image->setPixmap(nextImage);
        game.inventory.push_back(game.Safe1->getItem());
        ui->textinventory->setText(QString::fromStdString(game.getInventory()));

    }
    else if(room == "Safe2"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Safe.png");
        ui->image->setPixmap(nextImage);
        game.inventory.push_back(game.Safe2->getItem());
        ui->textinventory->setText(QString::fromStdString(game.getInventory()));


    }
    else if(room == "Safe3"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Safe.png");
        ui->image->setPixmap(nextImage);
        game.inventory.push_back(game.Safe3->getItem());
        ui->textinventory->setText(QString::fromStdString(game.getInventory()));
    }
    else if(room == "Safe4"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Safe.png");
        ui->image->setPixmap(nextImage);
        game.inventory.push_back(game.Safe4->getItem());
        ui->textinventory->setText(QString::fromStdString(game.getInventory()));
    }
    else if(room == "Safe5"){
        QPixmap nextImage("C:/Users/desir/C++ Project in QT/BarkNRollGame/Safe.png");
        ui->image->setPixmap(nextImage);
        game.inventory.push_back(game.Safe5->getItem());
        ui->textinventory->setText(QString::fromStdString(game.getInventory()));
    }
    else{return ;}
}



void MainWindow::on_yes_pressed()
{
    if(gameIsStarted && game.checkRoom() == "Gloomweavers" ){
        appendTextToConsole( "Well done! You've dispelled the dark magic misconception about dogs.\n"
                            " Instead of weaving webs, they're busy perfecting their skills in tail-wagging and belly rubs.");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happydog.png");//happy dog image
        ui->map->setPixmap(image); // no space t put another image display, so display in the map box

    }
    else if(gameIsStarted && game.checkRoom() == "Embermaws" ){
        appendTextToConsole("You did it! Raccoons don't leave fiery trails but they do leave a trail of mischief and trash can raiding.\n"
                            " Keep your snacks secure!");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happyraccoon.png"); //happy raccoon image
        ui->map->setPixmap(image);

    }
    else if(gameIsStarted && game.checkRoom() == "Wispfiends" ){
        appendTextToConsole("Moo-velous! You've discovered that cows are not ethereal phasers.\n"
                            " They'd rather focus on grazing grass, producing milk, and maybe even learning a few dance moves.");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happycow.png");// happycow image
        ui->map->setPixmap(image);

    }
    else if(gameIsStarted && game.checkRoom() == "Mindflayers" ){
        appendTextToConsole("Bravo! You've seen through the psychic illusion surrounding pandas. \n"
                            "Their true power lies in capturing hearts worldwide with their cuddly cuteness and bamboo-munching skills.");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happypanda.png"); //happy panda image
        ui->map->setPixmap(image);

    }
    else if(gameIsStarted && game.checkRoom() == "Chronomancers" ){
        appendTextToConsole("Congratulations! You've correctly uncovered the time-manipulating secrets of cats.\n"
                            " Now they can teach you the art of napping through the ages!");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happycat.png"); // happycat image
        ui->map->setPixmap(image);

    }
    else if(gameIsStarted && game.checkRoom() == "Boss" ){
        appendTextToConsole("Incredible! Hamsters aren't reality-bending cosmic beings. \n"
                            "Instead, they excel at running on wheels and stuffing their cheeks with food. The cutest little adventurers!\n"
                            "__________________________________________ \n"
                             "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/happyhamster.png"); // well done image, start again + happy hamster
        ui->map->setPixmap(image);
        gameIsStarted = false;
    }
    else return;
}


void MainWindow::on_no_pressed() //CHANGE IMAGE
{   if(gameIsStarted && game.checkRoom() == "Gloomweavers" ){
        appendTextToConsole("Oops! The dark magic web of misconception ensnares you. \n"
                            "The Gloomweaver dog absorbs your energy, leaving you weakened and defenseless. \n"
                            "Time to retreat and study up on doggy myths!\n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/saddog.png"); //saddog image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else if(gameIsStarted && game.checkRoom() == "Embermaws" ){
        appendTextToConsole("Watch out! The fiery path of the Embermaw raccoon proves too hot for you to handle.\n"
                            " You find yourself engulfed in flames, taking damage as the raccoon scurries away victoriously. \n"
                            "Keep your cool next time!\n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadraccoon.png"); //sad raccoon image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else if(gameIsStarted && game.checkRoom() == "Wispfiends" ){
        appendTextToConsole("Moo-ve along! Your knowledge about cow phasing isn't quite on point. \n"
                            "The Wispfiend cow effortlessly slips through walls and disappears, leaving you in a bewildered daze.\n"
                            " Keep chasing those elusive answers!\n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadcow.png"); //sad cow image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else if(gameIsStarted && game.checkRoom() == "Mindflayers" ){
        appendTextToConsole("Oh dear! Your mind has been skillfully manipulated by the Mindflayer panda. \n"
                            "Confusion takes over as you find yourself attacking your allies or unable to attack at all.\n"
                            " The panda triumphs, but don't lose hope!\n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadpanda.png"); //sad panda image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else if(gameIsStarted && game.checkRoom() == "Chronomancers" ){
        appendTextToConsole( "Oh no! Your understanding of cat chronomancy needs some work. \n"
                            "The Chronomancer cat seizes the opportunity and speeds away, leaving you behind in a time warp of confusion.\n"
                            " Better luck next time! \n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadcat.png"); //sad cat image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else if(gameIsStarted && game.checkRoom() == "Boss" ){
        appendTextToConsole( "Oh my! The cosmic powers of the Titan of Time and Space hamster are too overwhelming for you. \n"
                            "The fabric of reality warps, and you're transported to another dimension, defeated for now. \n"
                            "Keep exploring the mysteries of hamsters!\n"
                            "__________________________________________ \n"
                            "Press 'Start game' button, to start again");
        QPixmap image("C:/Users/desir/C++ Project in QT/BarkNRollGame/sadhamster.png"); //sad hamster image
        ui->map->setPixmap(image);
        gameIsStarted = false;

    }
    else return;
}


void MainWindow::on_drop_clicked()
{

    game.inventory.clear();
    ui->textinventory->clear();
}

