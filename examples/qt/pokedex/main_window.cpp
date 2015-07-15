#include "main_window.h"

MainWindow::MainWindow()
{
	// Title
	setWindowTitle("Pokedex");



	// Overall layout
	overallLayout = new QHBoxLayout();




	// // Selected pokemon display
	// Layout
	pokemonDisplayLayout = new QVBoxLayout();
	overallLayout->addLayout(pokemonDisplayLayout);

	// Pokemon image
	pokemonImageContainer = new QLabel();
	//TODO

	// Pokemon name
	pokemonNameDisplay = new QLabel();
	//TODO

	// Make it so image and name are at the top
	pokemonDisplayLayout->addStretch();




	// // List of all pokemon
	pokemonListWidget = new QListWidget();
	connect(pokemonListWidget, SIGNAL(currentRowChanged(int)),this, SLOT(displayPokemon(int)));
	overallLayout->addWidget(pokemonListWidget);
	//TODO




	// // Form to add pokemon
	// Layout
	formLayout = new QVBoxLayout();
	overallLayout->addLayout(formLayout);


	// Pokemon name label
	pokemonNameLabel = new QLabel("Pokemon's Name:");
	formLayout->addWidget(pokemonNameLabel);

	// Pokemon name input
	pokemonNameInput = new QLineEdit();
	formLayout->addWidget(pokemonNameInput);
	//TODO


	// Image filename label
	imageFilenameLabel = new QLabel("Image Filename:");
	formLayout->addWidget(imageFilenameLabel);

	// Image filename input
	imageFilenameInput = new QLineEdit();
	formLayout->addWidget(imageFilenameInput);
	//TODO


	// Add button
	addButton = new QPushButton("Add pokemon", this);
	formLayout->addWidget(addButton);
	connect(addButton, SIGNAL(clicked()), this, SLOT(addPokemon()));
	//TODO




	// Set overall layout
	setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
	// Delete the images
	for(std::vector<QImage*>::iterator i = pokemonImages.begin();
		i != pokemonImages.end();
		++i)
	{
		delete *i;
	}

	//TODO the delete UI objects
}



void MainWindow::addPokemon()
{
	// Do nothing if user left at least one input blank
	if((imageFilenameLabel->text().isEmpty()) || (pokemonNameInput->text().isEmpty())){return;}
	//TODO


	// // Get form values
	// Pokemon name
	pokemonNames.push_back(pokemonNameInput->text().toStdString());
	//TODO
	
	// Image
	QString filename = imageFilenameInput->text();
	QImage* newImage = new QImage();
	//TODO what should go right here?
	newImage->load(imageFilenameInput->text());
	pokemonImages.push_back(newImage);


	// Create a new list item with the pokemon's name
	pokemonListWidget->addItem(pokemonNameInput->text());
	//TODO


	// Clear the form inputs
	pokemonNameInput->setText("");
	imageFilenameInput->setText("");
	//TODO
}



void MainWindow::displayPokemon(int pokemonIndex)
{
	// Get the pokemon specified by the index,
	// which is passed into the function when
	// the user clicks on pokemonListWidget

	// Image
	QImage image = *pokemonImages[pokemonIndex];
	pokemonImageContainer->setPixmap(QPixmap::fromImage(image));
	pokemonDisplayLayout->addWidget(pokemonImageContainer);
	//TODO

	// Pokemon name

	QString name = QString::fromStdString(pokemonNames[pokemonIndex]);
	pokemonNameDisplay->setText(name);
	pokemonDisplayLayout->addWidget(pokemonNameDisplay);
	//TODO
}
