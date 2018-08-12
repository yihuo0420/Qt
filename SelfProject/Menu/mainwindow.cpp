﻿#include <QtWidgets>

#include "mainwindow.h"

XIAOHAI::MainWindow::MainWindow(QWidget *parent) {
  QWidget *widget = new QWidget(this);
  setCentralWidget(widget);

  QWidget *topFiller = new QWidget;
  topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  infoLabel = new QLabel(
      tr("<i>Choose a menu option, or right-click to invoke a context"
         "menu</i>"));
  infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
  infoLabel->setAlignment(Qt::AlignCenter);

  QWidget *bottomFiller = new QWidget;
  bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(5);
  layout->addWidget(topFiller);
  layout->addWidget(infoLabel);
  layout->addWidget(bottomFiller);
  widget->setLayout(layout);

  createActions();
  createMenus();

  QString message = tr("A context menu is available by right-clicking");
  statusBar()->showMessage(message);

  setWindowTitle(tr("Menus"));
  setMinimumSize(160, 160);
  resize(480, 320);
}

#ifndef QT_NO_CONTEXTMENU
void XIAOHAI::MainWindow::contextMenuEvent(QContextMenuEvent *event) {
  QMenu menu(this);
  menu.addAction(cutAct);
  menu.addAction(copyAct);
  menu.addAction(pasteAct);
  menu.exec(event->globalPos());
}
#endif  ///< QT_NO_CONTEXTMENU

void XIAOHAI::MainWindow::newFile() {
  infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void XIAOHAI::MainWindow::open() {
  infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void XIAOHAI::MainWindow::save() {
  infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void XIAOHAI::MainWindow::print() {
  infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void XIAOHAI::MainWindow::undo() {
  infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
}

void XIAOHAI::MainWindow::redo() {
  infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
}

void XIAOHAI::MainWindow::cut() {
  infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void XIAOHAI::MainWindow::copy() {
  infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void XIAOHAI::MainWindow::paste() {
  infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void XIAOHAI::MainWindow::bold() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Bold</b>"));
}

void XIAOHAI::MainWindow::italic() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Italic</b>"));
}

void XIAOHAI::MainWindow::leftAlign() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Left Align</b>"));
}

void XIAOHAI::MainWindow::rightAlign() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Right Align</b>"));
}

void XIAOHAI::MainWindow::justify() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Justify</b>"));
}

void XIAOHAI::MainWindow::center() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Center</b>"));
}

void XIAOHAI::MainWindow::setLineSpacing() {
  infoLabel->setText("Invoked <b>Edit|Format|Set Line Spacing</b>");
}

void XIAOHAI::MainWindow::setParagraphSpacing() {
  infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"));
}

void XIAOHAI::MainWindow::about() {
  infoLabel->setText(tr("Invoked <b>Help|About</b>"));
  QMessageBox::about(this, tr("About Menu"),
                     tr("The <b>Menu</b> example shows how to create menu-bar "
                        "menus and context menus."));
}

void XIAOHAI::MainWindow::aboutQt() {
  infoLabel->setText(tr("Invoked <b>Help|About Qt.</b>"));
}

void XIAOHAI::MainWindow::createActions() {
  newAct = new QAction(tr("&New"), this);
  newAct->setShortcuts(QKeySequence::New);
  newAct->setStatusTip(tr("Create a new file"));
  connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

  openAct = new QAction(tr("&Open"), this);
  openAct->setShortcuts(QKeySequence::Open);
  openAct->setStatusTip(tr("Open an existing file"));
  connect(openAct, &QAction::triggered, this, &MainWindow::open);

  saveAct = new QAction(tr("&Save"), this);
  saveAct->setShortcuts(QKeySequence::Save);
  saveAct->setStatusTip(tr("Save the document to disk"));
  connect(saveAct, &QAction::triggered, this, &MainWindow::save);

  printAct = new QAction(tr("&Print..."), this);
  printAct->setShortcuts(QKeySequence::Print);
  printAct->setStatusTip(tr("Print the document"));
  connect(printAct, &QAction::triggered, this, &MainWindow::print);

  exitAct = new QAction(tr("E&xit"), this);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));
  connect(exitAct, &QAction::triggered, this, &MainWindow::close);

  undoAct = new QAction(tr("&Undo"), this);
  exitAct->setShortcuts(QKeySequence::Undo);
  exitAct->setStatusTip(tr("Undo the last operation"));
  connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

  redoAct = new QAction(tr("&Redo"), this);
  redoAct->setShortcuts(QKeySequence::Redo);
  redoAct->setStatusTip(tr("Redo the last operation"));
  connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

  cutAct = new QAction(tr("Cu&t"), this);
  cutAct->setShortcuts(QKeySequence::Cut);
  cutAct->setStatusTip(
      tr("Cut he current selection's contents to the clipboard"));
  connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

  copyAct = new QAction(tr("&Copy"), this);
  copyAct->setShortcuts(QKeySequence::Copy);
  copyAct->setStatusTip(
      tr("Copy the current selection's contents to the clipboard"));
  connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

  pasteAct = new QAction(tr("&Paste"), this);
  pasteAct->setShortcuts(QKeySequence::Paste);
  pasteAct->setStatusTip(
      tr("Paste the clipboard's contents into the current selection"));

  boldAct = new QAction(tr("&Bold"), this);
  boldAct->setCheckable(true);
  boldAct->setShortcut(QKeySequence::Bold);
  boldAct->setStatusTip(tr("Make the text bold"));
  connect(boldAct, &QAction::triggered, this, &MainWindow::bold);
  QFont boldFont = boldAct->font();
  boldFont.setBold(true);
  boldAct->setFont(boldFont);

  italicAct = new QAction(tr("&Italic"), this);
  italicAct->setCheckable(true);
  italicAct->setShortcut(QKeySequence::Italic);
  italicAct->setStatusTip(tr("Make the text italic"));
  connect(italicAct, &QAction::triggered, this, &MainWindow::italic);
  QFont italicFont = italicAct->font();
  italicFont.setItalic(true);
  italicAct->setFont(italicFont);

  setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
  setLineSpacingAct->setStatusTip(
      tr("Change the gap between the lines of a paragraph"));
  connect(setLineSpacingAct, &QAction::triggered, this,
          &MainWindow::setLineSpacing);

  setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
  setParagraphSpacingAct->setStatusTip(tr("Change the gap between paragraphs"));
  connect(setParagraphSpacingAct, &QAction::triggered, this,
          &MainWindow::setParagraphSpacing);

  aboutAct = new QAction(tr("&About"), this);
  aboutAct->setStatusTip(tr("Show the application's About box"));
  connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

  aboutQtAct = new QAction(tr("&About Qt"), this);
  aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
  connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
  connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

  leftAlignAct = new QAction(tr("&Left Align"), this);
  leftAlignAct->setCheckable(true);
  leftAlignAct->setShortcut(tr("Ctrl+L"));
  leftAlignAct->setStatusTip(tr("Left align the selected text"));
  connect(leftAlignAct, &QAction::triggered, this, &MainWindow::leftAlign);

  rightAlignAct = new QAction(tr("&Right Align"), this);
  rightAlignAct->setCheckable(true);
  rightAlignAct->setShortcut(tr("Ctrl+R"));
  rightAlignAct->setStatusTip(tr("Right align the selected text"));
  connect(rightAlignAct, &QAction::triggered, this, &MainWindow::rightAlign);

  justifyAct = new QAction(tr("&Justify"), this);
  justifyAct->setCheckable(true);
  justifyAct->setShortcut(tr("Ctrl+J"));
  justifyAct->setStatusTip(tr("Justify align the selected text"));
  connect(justifyAct, &QAction::triggered, this, &MainWindow::justify);

  centerAct = new QAction(tr("&Right Align"), this);
  centerAct->setCheckable(true);
  centerAct->setShortcut(tr("Ctrl+R"));
  centerAct->setStatusTip(tr("Right align the selected text"));
  connect(centerAct, &QAction::triggered, this, &MainWindow::center);

  alignmentGroup = new QActionGroup(this);
  alignmentGroup->addAction(leftAlignAct);
  alignmentGroup->addAction(rightAlignAct);
  alignmentGroup->addAction(justifyAct);
  alignmentGroup->addAction(centerAct);
  leftAlignAct->setChecked(true);
}

void XIAOHAI::MainWindow::createMenus() {
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(newAct);
  fileMenu->addAction(openAct);
  fileMenu->addAction(saveAct);
  fileMenu->addAction(printAct);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAct);

  editMenu = menuBar()->addMenu(tr("&Edit"));
  editMenu->addAction(undoAct);
  editMenu->addAction(redoAct);
  editMenu->addSeparator();
  editMenu->addAction(cutAct);
  editMenu->addAction(copyAct);
  editMenu->addAction(pasteAct);
  editMenu->addSeparator();

  helpMenu = menuBar()->addMenu(tr("&Help"));
  helpMenu->addAction(aboutAct);
  helpMenu->addAction(aboutQtAct);

  formatMenu = editMenu->addMenu(tr("&Format"));
  formatMenu->addAction(boldAct);
  formatMenu->addAction(italicAct);
  formatMenu->addSeparator()->setText(tr("Alignment"));
  formatMenu->addAction(leftAlignAct);
  formatMenu->addAction(rightAlignAct);
  formatMenu->addAction(justifyAct);
  formatMenu->addAction(centerAct);
  formatMenu->addSeparator();
  formatMenu->addAction(setLineSpacingAct);
  formatMenu->addAction(setParagraphSpacingAct);
}