#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(2);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(0, 360);

	auto span = 30;
	ofColor color;
	for (int base_y = 0; base_y < 720; base_y += 180) {

		color.setHsb(ofMap(base_y, 0, 720, 0, 255), 255, 255);
		for (int x = 0; x <= 720; x += span) {

			for (int i = 0; i < 5; i++) {

				auto y = ofMap(ofNoise(base_y * 0.003, x * 0.003 + (ofGetFrameNum() - i * 2) * 0.008), 0, 1, -300, 300);
				auto radius = ofMap(i, 0, 5, span * 0.8, span * 0.01);

				ofSetColor(color, ofMap(i, 0, 5, 255, 0));
				ofDrawCircle(x, y, radius);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}