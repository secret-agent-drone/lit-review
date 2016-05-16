{

  const int nmodes=6;
  const char *modes[nmodes] = {"#tau^{-} #rightarrow #mu^{-} #gamma", "#tau^{-} #rightarrow e^{-} #gamma", "#tau^{-} #rightarrow #mu^{+} #mu^{-} #mu^{-}", "#tau^{-} #rightarrow e^{+} e^{-} e^{-}", "#tau^{-} #rightarrow #mu^{-} #pi^{0}", "#tau^{-} #rightarrow e^{-} #pi^{0}"};

  Double_t ypointsBabar[nmodes]   ={4.4e-8, 3.3e-8, 3.3e-8, 2.9e-8,11e-8, 13e-8};
  Double_t xpointsBabar[nmodes]   ={1+0.2,2+0.2,3+0.2,4+0.2,5+0.2,6+0.2};

  Double_t ypointsLHCb[1]   ={4.6e-8};
  Double_t xpointsLHCb[1]   ={3.5};

  Double_t ypointsLHCb_23fb[1]   ={1.4e-8};
  Double_t xpointsLHCb_23fb[1]   ={3.5};

  Double_t ypointsBelle[nmodes]   ={4.5e-8, 1.2e-7, 2.1e-8, 2.7e-8, 2.7e-8, 2.2e-8};
  Double_t xpointsBelle[nmodes]   ={1+0.8,2+0.8,3+0.8,4+0.8, 5+0.8, 6+0.8};

  Double_t ypointsBelle2_5ab[nmodes]   ={1.5e-8, 3.9e-8, 3.3e-9, 4.2e-9, 1.2e-8, 9.3e-9};
  Double_t xpointsBelle2_5ab[nmodes]   ={1+0.8,2+0.8,3+0.8,4+0.8, 5+0.8, 6+0.8};

  Double_t ypointsBelle2_50ab[nmodes]  ={4.7e-9, 1.2e-8, 3.3e-10, 4.2e-10, 3.6e-9, 3.0e-9};
  Double_t xpointsBelle2_50ab[nmodes]  ={1+0.8,2+0.8,3+0.8,4+0.8, 5+0.8, 6+0.8};

  TH2F *ths = new TH2F("ths","ths;;90% C.L. upper limits for LFV #tau Decays",nmodes,1.0,7.0, 20., 1e-10, 2.e-7);

  for (int i=1;i<=nmodes;i++) ths->GetXaxis()->SetBinLabel(i,modes[i-1]);

  TGraph *tgBelle = new TGraphAsymmErrors(nmodes,xpointsBelle,ypointsBelle);
  TGraph *tgBabar = new TGraphAsymmErrors(nmodes,xpointsBabar,ypointsBabar);
  TGraph *tgBelle2_5ab = new TGraphAsymmErrors(nmodes,xpointsBelle2_5ab,ypointsBelle2_5ab);
  TGraph *tgBelle2_50ab = new TGraphAsymmErrors(nmodes,xpointsBelle2_50ab,ypointsBelle2_50ab);

  TGraph *tgLHCb      = new TGraphAsymmErrors(nmodes,xpointsLHCb,ypointsLHCb);
  TGraph *tgLHCb_23fb = new TGraphAsymmErrors(nmodes,xpointsLHCb_23fb,ypointsLHCb_23fb);

  tgBelle->SetLineColor(kRed);
  tgBelle->SetMarkerColor(kRed);
  tgBelle->SetMarkerStyle(22);

  tgBabar->SetLineColor(kBlue);
  tgBabar->SetMarkerColor(kBlue);
  tgBabar->SetMarkerStyle(23);

  tgBelle2_5ab->SetLineColor(kMagenta);
  tgBelle2_5ab->SetMarkerColor(kMagenta);
  tgBelle2_5ab->SetMarkerStyle(26);

  tgBelle2_50ab->SetLineColor(kMagenta+2);
  tgBelle2_50ab->SetMarkerColor(kMagenta+2);
  tgBelle2_50ab->SetMarkerStyle(26);

  tgLHCb->SetLineColor(kBlack);
  tgLHCb->SetMarkerColor(kBlack);
  tgLHCb->SetMarkerStyle(21);

  tgLHCb_23fb->SetLineColor(kBlack);
  tgLHCb_23fb->SetMarkerColor(kBlack);
  tgLHCb_23fb->SetMarkerStyle(25);

  //  TCanvas *tc = new TCanvas("tc","tc",800,900);
  TCanvas *tc = new TCanvas("tc","tc",1000,500);
  tc->cd()->SetLogy(1);
  tc->cd()->SetGridy(1);
  tc->cd()->SetGridx(1);
  // ths->GetXaxis()->CenterTitle();
  ths->GetXaxis()->CenterLabels();
  ths->GetXaxis()->SetNdivisions(-505);
  ths->Draw();

  tgBabar->Draw("p");
  tgBelle->Draw("p");
  tgBelle2_5ab->Draw("p");
  tgBelle2_50ab->Draw("p");
  tgLHCb->Draw("p");  
  tgLHCb_23fb->Draw("p");

  myLegend = new TLegend(0.76,0.5,0.95,0.9);
  myLegend->SetBorderSize(0);
  myLegend->SetTextSize(0.04);
  myLegend->AddEntry(tgBabar,"Babar","p");
  myLegend->AddEntry(tgLHCb,"LHCb","p");
  myLegend->AddEntry(tgLHCb_23fb,"LHCb 23 fb^{-1}","p");
  myLegend->AddEntry(tgBelle,"Belle","p");
  myLegend->AddEntry(tgBelle2_5ab,"Belle II 5 ab^{-1}","p");
  myLegend->AddEntry(tgBelle2_50ab,"Belle II 50 ab^{-1}","p");
  myLegend->Draw();


  //  gPad->RedrawAxis();

  tc->SaveAs("tauLFV.pdf");

}
